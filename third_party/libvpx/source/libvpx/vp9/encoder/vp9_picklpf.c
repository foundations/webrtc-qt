/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include <assert.h>
#include <limits.h>
#include "vp9/common/vp9_onyxc_int.h"
#include "vp9/encoder/vp9_onyx_int.h"
#include "vp9/encoder/vp9_picklpf.h"
#include "vp9/encoder/vp9_quantize.h"
#include "vp9/common/vp9_quant_common.h"
#include "vpx_mem/vpx_mem.h"
#include "vpx_scale/vpx_scale.h"
#include "vp9/common/vp9_alloccommon.h"
#include "vp9/common/vp9_loopfilter.h"
#include "./vpx_scale_rtcd.h"

static int get_min_filter_level(VP9_COMP *cpi, int base_qindex) {
  return 0;
}

static int get_max_filter_level(VP9_COMP *cpi, int base_qindex) {
  return cpi->twopass.section_intra_rating > 8 ? MAX_LOOP_FILTER * 3 / 4
                                               : MAX_LOOP_FILTER;
}

// Stub function for now Alt LF not used
void vp9_set_alt_lf_level(VP9_COMP *cpi, int filt_val) {
}

static int try_filter_frame(const YV12_BUFFER_CONFIG *sd, VP9_COMP *const cpi,
                            MACROBLOCKD *const xd, VP9_COMMON *const cm,
                            int filt_level, int partial) {
  int filt_err;

  vp9_set_alt_lf_level(cpi, filt_level);
  vp9_loop_filter_frame(cm, xd, filt_level, 1, partial);

  filt_err = vp9_calc_ss_err(sd, cm->frame_to_show);

  // Re-instate the unfiltered frame
  vpx_yv12_copy_y(&cpi->last_frame_uf, cm->frame_to_show);

  return filt_err;
}

static void search_filter_level(const YV12_BUFFER_CONFIG *sd, VP9_COMP *cpi,
                                int partial) {
  MACROBLOCKD *const xd = &cpi->mb.e_mbd;
  VP9_COMMON *const cm = &cpi->common;
  struct loopfilter *const lf = &cm->lf;
  const int min_filter_level = get_min_filter_level(cpi, cm->base_qindex);
  const int max_filter_level = get_max_filter_level(cpi, cm->base_qindex);
  int best_err;
  int filt_best;
  int filt_direction = 0;
  // Start the search at the previous frame filter level unless it is now out of
  // range.
  int filt_mid = clamp(lf->filter_level, min_filter_level, max_filter_level);
  int filter_step = filt_mid < 16 ? 4 : filt_mid / 4;
  // Sum squared error at each filter level
  int ss_err[MAX_LOOP_FILTER + 1];

  // Set each entry to -1
  vpx_memset(ss_err, 0xFF, sizeof(ss_err));

  //  Make a copy of the unfiltered / processed recon buffer
  vpx_yv12_copy_y(cm->frame_to_show, &cpi->last_frame_uf);

  best_err = try_filter_frame(sd, cpi, xd, cm, filt_mid, partial);
  filt_best = filt_mid;
  ss_err[filt_mid] = best_err;

  while (filter_step > 0) {
    const int filt_high = MIN(filt_mid + filter_step, max_filter_level);
    const int filt_low = MAX(filt_mid - filter_step, min_filter_level);
    int filt_err;

    // Bias against raising loop filter in favor of lowering it.
    int bias = (best_err >> (15 - (filt_mid / 8))) * filter_step;

    if (cpi->twopass.section_intra_rating < 20)
      bias = bias * cpi->twopass.section_intra_rating / 20;

    // yx, bias less for large block size
    if (cm->tx_mode != ONLY_4X4)
      bias >>= 1;

    if (filt_direction <= 0 && filt_low != filt_mid) {
      // Get Low filter error score
      if (ss_err[filt_low] < 0) {
        filt_err = try_filter_frame(sd, cpi, xd, cm, filt_low, partial);
        ss_err[filt_low] = filt_err;
      } else {
        filt_err = ss_err[filt_low];
      }
      // If value is close to the best so far then bias towards a lower loop
      // filter value.
      if ((filt_err - bias) < best_err) {
        // Was it actually better than the previous best?
        if (filt_err < best_err)
          best_err = filt_err;

        filt_best = filt_low;
      }
    }

    // Now look at filt_high
    if (filt_direction >= 0 && filt_high != filt_mid) {
      if (ss_err[filt_high] < 0) {
        filt_err = try_filter_frame(sd, cpi, xd, cm, filt_high, partial);
        ss_err[filt_high] = filt_err;
      } else {
        filt_err = ss_err[filt_high];
      }
      // Was it better than the previous best?
      if (filt_err < (best_err - bias)) {
        best_err = filt_err;
        filt_best = filt_high;
      }
    }

    // Half the step distance if the best filter value was the same as last time
    if (filt_best == filt_mid) {
      filter_step = filter_step / 2;
      filt_direction = 0;
    } else {
      filt_direction = (filt_best < filt_mid) ? -1 : 1;
      filt_mid = filt_best;
    }
  }

  lf->filter_level = filt_best;
}

void vp9_pick_filter_level(const YV12_BUFFER_CONFIG *sd, VP9_COMP *cpi,
                           int method) {
  VP9_COMMON *const cm = &cpi->common;
  struct loopfilter *const lf = &cm->lf;

  lf->sharpness_level = cm->frame_type == KEY_FRAME ? 0
                                                    : cpi->oxcf.sharpness;

  if (method == 2) {
    const int min_filter_level = get_min_filter_level(cpi, cm->base_qindex);
    const int max_filter_level = get_max_filter_level(cpi, cm->base_qindex);
    const int q = vp9_ac_quant(cm->base_qindex, 0);
    // These values were determined by linear fitting the result of the
    // searched level
    // filt_guess = q * 0.316206 + 3.87252
    int filt_guess = (q * 20723 + 1015158 + (1 << 17)) >> 18;
    if (cm->frame_type == KEY_FRAME)
      filt_guess -= 4;
    lf->filter_level = clamp(filt_guess, min_filter_level, max_filter_level);
  } else {
    search_filter_level(sd, cpi, method == 1);
  }
}
