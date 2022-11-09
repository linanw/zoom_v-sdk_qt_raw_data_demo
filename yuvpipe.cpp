#include "yuvpipe.h"

YUVPipe::YUVPipe(IZoomVideoSDKUser *user, OpenGLDisplay* display)
{
    user->GetVideoPipe()->subscribe(ZOOMVIDEOSDK::ZoomVideoSDKResolution_360P, this);
    user_ = user;
    display_ = display;
    ObjectDetect_ = new OpenCVObjectDetect();
}

void YUVPipe::onRawDataFrameReceived(YUVRawDataI420 *data)
{
    int width = data->GetStreamWidth();
    int heigth = data->GetStreamHeight();
    int bufferSize = data->GetBufferLen();
    uchar* frame_in = reinterpret_cast<unsigned char *>(data->GetBuffer());

    uchar frame_out[bufferSize];
    ObjectDetect_->TagObject(frame_in, frame_out, width, heigth);
    display_->DisplayVideoFrame(frame_out, width, heigth);
}

void YUVPipe::onRawDataStatusChanged(RawDataStatus status){}
