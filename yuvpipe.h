#ifndef YUVPIPE_H
#define YUVPIPE_H

#include "OpenGLDisplay.h"
#include "helpers/zoom_video_sdk_user_helper_interface.h"
#include "zoom_video_sdk_def.h"
#include "OpenCVObjectDetect.h"

USING_ZOOM_VIDEO_SDK_NAMESPACE

class YUVPipe : public IZoomVideoSDKRawDataPipeDelegate
{
    IZoomVideoSDKUser *user_;
    OpenGLDisplay* display_;
    OpenCVObjectDetect* ObjectDetect_;
public:
    YUVPipe(IZoomVideoSDKUser *user, OpenGLDisplay* display);
    void onRawDataStatusChanged(RawDataStatus status);
    void onRawDataFrameReceived(YUVRawDataI420 *data);
};

#endif // YUVPIPE_H
