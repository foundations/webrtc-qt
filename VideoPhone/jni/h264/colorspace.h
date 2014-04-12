/*
 * Colorspace conversion defines
 * Copyright (c) 2001, 2002, 2003 Fabrice Bellard.
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file colorspace.h
 * Various defines for YUV<->RGB conversion
 */

#ifndef FFMPEG_COLORSPACE_H
#define FFMPEG_COLORSPACE_H

#define SCALEBITS 10
#define ONE_HALF  (1 << (SCALEBITS - 1))
#define FIX(x)    ((int) ((x) * (1<<SCALEBITS) + 0.5))

#define YUV_TO_RGB1_CCIR(cb1, cr1)\
{\
    cb = (cb1) - 128;\
    cr = (cr1) - 128;\
    r_add = FIX(1.40200*255.0/224.0) * cr + ONE_HALF;\
    g_add = - FIX(0.34414*255.0/224.0) * cb - FIX(0.71414*255.0/224.0) * cr + \
            ONE_HALF;\
    b_add = FIX(1.77200*255.0/224.0) * cb + ONE_HALF;\
}

#define YUV_TO_RGB2_CCIR(r, g, b, y1)\
{\
    y = ((y1) - 16) * FIX(255.0/219.0);\
    r = cm[(y + r_add) >> SCALEBITS];\
    g = cm[(y + g_add) >> SCALEBITS];\
    b = cm[(y + b_add) >> SCALEBITS];\
}

#define YUV_TO_RGB1(cb1, cr1)\
{\
    cb = (cb1) - 128;\
    cr = (cr1) - 128;\
    r_add = FIX(1.40200) * cr + ONE_HALF;\
    g_add = - FIX(0.34414) * cb - FIX(0.71414) * cr + ONE_HALF;\
    b_add = FIX(1.77200) * cb + ONE_HALF;\
}

#define YUV_TO_RGB2(r, g, b, y1)\
{\
    y = (y1) << SCALEBITS;\
    r = cm[(y + r_add) >> SCALEBITS];\
    g = cm[(y + g_add) >> SCALEBITS];\
    b = cm[(y + b_add) >> SCALEBITS];\
}

#define Y_CCIR_TO_JPEG(y)\
 cm[((y) * FIX(255.0/219.0) + (ONE_HALF - 16 * FIX(255.0/219.0))) >> SCALEBITS]

#define Y_JPEG_TO_CCIR(y)\
 (((y) * FIX(219.0/255.0) + (ONE_HALF + (16 << SCALEBITS))) >> SCALEBITS)

#define C_CCIR_TO_JPEG(y)\
 cm[(((y) - 128) * FIX(127.0/112.0) + (ONE_HALF + (128 << SCALEBITS))) >> SCALEBITS]

/* NOTE: the clamp is really necessary! */
static    int C_JPEG_TO_CCIR(int y) {
    y = (((y - 128) * FIX(112.0/127.0) + (ONE_HALF + (128 << SCALEBITS))) >> SCALEBITS);
    if (y < 16)
        y = 16;
    return y;
}


#define RGB_TO_Y(r, g, b) \
((FIX(0.29900) * (r) + FIX(0.58700) * (g) + \
  FIX(0.11400) * (b) + ONE_HALF) >> SCALEBITS)

#define RGB_TO_U(r1, g1, b1, shift)\
(((- FIX(0.16874) * r1 - FIX(0.33126) * g1 +         \
     FIX(0.50000) * b1 + (ONE_HALF << shift) - 1) >> (SCALEBITS + shift)) + 128)

#define RGB_TO_V(r1, g1, b1, shift)\
(((FIX(0.50000) * r1 - FIX(0.41869) * g1 -           \
   FIX(0.08131) * b1 + (ONE_HALF << shift) - 1) >> (SCALEBITS + shift)) + 128)

#define RGB_TO_Y_CCIR(r, g, b) \
((FIX(0.29900*219.0/255.0) * (r) + FIX(0.58700*219.0/255.0) * (g) + \
  FIX(0.11400*219.0/255.0) * (b) + (ONE_HALF + (16 << SCALEBITS))) >> SCALEBITS)

#define RGB_TO_U_CCIR(r1, g1, b1, shift)\
(((- FIX(0.16874*224.0/255.0) * r1 - FIX(0.33126*224.0/255.0) * g1 +         \
     FIX(0.50000*224.0/255.0) * b1 + (ONE_HALF << shift) - 1) >> (SCALEBITS + shift)) + 128)

#define RGB_TO_V_CCIR(r1, g1, b1, shift)\
(((FIX(0.50000*224.0/255.0) * r1 - FIX(0.41869*224.0/255.0) * g1 -           \
   FIX(0.08131*224.0/255.0) * b1 + (ONE_HALF << shift) - 1) >> (SCALEBITS + shift)) + 128)

#endif /* FFMPEG_COLORSPACE_H */
