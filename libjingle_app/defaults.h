/*
 * libjingle
 * Copyright 2011, Google Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PEERCONNECTION_SAMPLES_CLIENT_DEFAULTS_H_
#define PEERCONNECTION_SAMPLES_CLIENT_DEFAULTS_H_

#include <string>
#include "talk/base/basictypes.h"
namespace kaerp2p{


extern const char kAudioLabel[];
extern const char kVideoLabel[];
extern const char kStreamLabel[];


extern const char kKaerMsgTypeName[];
extern const char kKaerMsgCommandName[];
extern const char kKaerTunnelMsgTypeValue[] ;
extern const char kKaerPTZCommandValue[];


extern const uint16 kDefaultServerPort;

enum FrameResolutionType{
    kFrameD1 = 0,
    kFrameQCIF = 1,
    kFrameCIF = 2,
    kFrameHD1 = 3,
    kFrameQVGA = 4,
    kFrame1080P = 6,
    kFrameVGA = 7,
    kFrame720P = 10,
    kFrame920P = 12,
};

struct VideoInfo{
    int frameRate;
    int frameResolution;//a enumirate of FrameResolutionType
};

std::string GetRandomString();
//yyyy-MM-dd hh:mm:ss---- %F %T
std::string GetCurrentDatetime(std::string format);


std::string GetEnvVarOrDefault(const char* env_var_name,
                               const char* default_value);
std::string GetPeerConnectionString();
std::string GetDefaultServerName();
std::string GetPeerName();

std::string GetConfigFileString(std::string filename);

std::string GetAppFilePath(std::string filename);
}
#endif  // PEERCONNECTION_SAMPLES_CLIENT_DEFAULTS_H_
