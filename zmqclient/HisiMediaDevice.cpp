#include "HisiMediaDevice.h"

#include "keapi/keapi.h"
#include "talk/base/bind.h"
#include "talk/base/thread.h"
#define VIDEO1_DATA				"video1_data"

struct MediaRequest{
    int video;
    int audio;
};

typedef talk_base::ScopedMessageData<MediaRequest> MediaRequestMessage;

HisiMediaDevice::HisiMediaDevice()
{
    process_ = new KeMessageProcessCamera();
    process_->SignalRecvAskMediaMsg.connect(this,&HisiMediaDevice::OnMediaRequest);
    media_thread_ = new talk_base::Thread();
    media_thread_->Start();
    Raycomm_MediaDataInit();
    video_handle_ = 0;
}

HisiMediaDevice::~HisiMediaDevice()
{
    Raycomm_MediaDataUnInit();
    delete media_thread_;
    delete process_;
}

void HisiMediaDevice::OnTunnelOpend(PeerTerminalInterface *t, const std::string &peer_id)
{
    process_->SetTerminal(peer_id,t);

}

void HisiMediaDevice::OnMediaRequest(int video,int audio)
{
    media_thread_->Invoke<int>(
        talk_base::Bind(&HisiMediaDevice::MediaControl_m,this,video,audio));
}

int HisiMediaDevice::MediaControl_m(int video, int audio)
{
    if(video == 0 && video_handle_ == 0){
        video_handle_ =  Raycomm_ConnectMedia(VIDEO1_DATA,0);
        media_thread_->Post(this,HisiMediaDevice::MSG_SEND_VIDEO);
    }
    else{
        Raycomm_DisConnectMedia(video_handle_);
        video_handle_ = 0;
    }
}

void HisiMediaDevice::OnMessage(talk_base::Message *msg)
{
    switch (msg->message_id) {
    case HisiMediaDevice::MSG_SEND_VIDEO:{
        if(video_handle_ == 0){
            break;
        }
        unsigned int timespan;
        int media_len;
        media_len = Raycomm_GetMediaData(video_handle_,media_buffer_,MEDIA_BUFFER_LENGTH,&timespan);
        if(media_len > 0){
            process_->SendMediaMsg(KEMSG_TYPE_VIDEOSTREAM,media_buffer_,media_len);
            media_thread_->Post(this,HisiMediaDevice::MSG_SEND_VIDEO);
        }
        else{
            media_thread_->PostDelayed(40,this,HisiMediaDevice::MSG_SEND_VIDEO);
        }
        break;
    }
    default:
            break;

    }
}