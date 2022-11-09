#include "widget.h"

#include <QApplication>
#include "zoom_video_sdk_api.h"
#include "zoom_video_sdk_def.h"
#include "zoom_video_sdk_delegate_interface.h"
#include "zoom_video_sdk_interface.h"
#include "zoomvideosdkdelegate.h"

USING_ZOOM_VIDEO_SDK_NAMESPACE

IZoomVideoSDK* video_sdk_obj;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    Widget w;
    w.show();

    QObject::connect(&a, &QApplication::lastWindowClosed, [=](){
        video_sdk_obj->leaveSession(false);
    });

    video_sdk_obj = CreateZoomVideoSDKObj();
    ZoomVideoSDKInitParams init_params;
    init_params.domain = "https://go.zoom.us";
    init_params.enableLog = true;
    init_params.logFilePrefix = "zoom_v-sdk_linux_bot";
    init_params.videoRawDataMemoryMode = ZoomVideoSDKRawDataMemoryModeHeap;
    init_params.shareRawDataMemoryMode = ZoomVideoSDKRawDataMemoryModeHeap;
    init_params.audioRawDataMemoryMode = ZoomVideoSDKRawDataMemoryModeHeap;
    init_params.enableIndirectRawdata = false;

    ZoomVideoSDKErrors err = video_sdk_obj->initialize(init_params);
    if (err != ZoomVideoSDKErrors_Success)
    {
        printf("error: %d", err);
    }
    else
    {
        IZoomVideoSDKDelegate *listener = new ZoomVideoSDKDelegate(&w);
        video_sdk_obj->addListener(dynamic_cast<IZoomVideoSDKDelegate *>(listener));
        ZoomVideoSDKSessionContext session_context;
        session_context.sessionName = "test";
        session_context.sessionPassword = "123";
        session_context.userName = "QT6 Session Watcher";
        session_context.token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhcHBfa2V5IjoiQ3MyNDJwMWFDV1lxdTlCYkVlRTRwUWZESmhCZGwyM2UzaFhzIiwidmVyc2lvbiI6MSwiaWF0IjoxNjY3OTg1OTY0LCJ1c2VyX2lkZW50aXR5IjoiMTIzIiwiZXhwIjoxNjY4MTU4NzY0LCJ0cGMiOiJUZXN0Iiwic2Vzc2lvbl9rZXkiOiIiLCJyb2xlX3R5cGUiOjF9.QmyfTiFiPxjSwUgAm8SWk72hzNkY6Jn8ImdSCcxXJpM";
        session_context.videoOption.localVideoOn = false; // (video_index >= 0); // if no video source arg, turn it off.
        session_context.audioOption.connect = false;
        session_context.audioOption.mute = true;
        IZoomVideoSDKSession *session = NULL;
        if (video_sdk_obj)
        {
            session = video_sdk_obj->joinSession(session_context);
        }
    }

    return a.exec();
}
