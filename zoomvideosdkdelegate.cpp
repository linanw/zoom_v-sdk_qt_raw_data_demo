#include "zoomvideosdkdelegate.h"

ZoomVideoSDKDelegate::ZoomVideoSDKDelegate(Widget* widget){
//    app_ = app;
    widget_ = widget;
}

    void ZoomVideoSDKDelegate::onSessionJoin()
        {
            printf("Joined session successfully.\n");
            // if (video_index >= 0)
            //     printf("Camera is on.\n");
            // if (is_to_record)
            //     printf("Recoding is on.\n");

        }

        /// \brief Triggered when session leaveSession
        void ZoomVideoSDKDelegate::onSessionLeave()
        {
            // g_main_loop_unref(loop);
            printf("Already left session.\n");
            QCoreApplication::exit(0);
            //exit(1);
        }

        /// \brief Triggered when session error.
        /// \param errorCode for more details, see \link ZoomVideoSDKErrors \endlink.
        /// \param detailErrorCode Detailed errorCode.
         void ZoomVideoSDKDelegate::onError(ZoomVideoSDKErrors errorCode, int detailErrorCode)
        {
            printf("join session errorCode : %d  detailErrorCode: %d\n", errorCode, detailErrorCode);
        }

        /// \brief Triggered when myself or other user join session.
        /// \param pUserHelper is the pointer to user helper object, see \link IZoomVideoSDKUserHelper \endlink.
        /// \param userList is the pointer to user object list.
         void ZoomVideoSDKDelegate::onUserJoin(IZoomVideoSDKUserHelper *pUserHelper, IVideoSDKVector<IZoomVideoSDKUser *> *userList)
        {
            if (userList)
            {
                int count = userList->GetCount();
                for (int index = 0; index < count; index++)
                {
                    IZoomVideoSDKUser *user = userList->GetItem(index);
                    if (user)
                    {
                        // if (is_to_record)
                        //     RawDataFFMPEGEncoder *encoder = new RawDataFFMPEGEncoder(user);
                        //RawDataProcessor *processor = new RawDataProcessor(user, yuv_);
                        OpenGLDisplay* display = new OpenGLDisplay(widget_);
                        widget_->addDisplay(display);
                        YUVPipe* yuv = new YUVPipe(user, display);
                    }
                }
            }
        }

        /// \brief Triggered when other users leave session.
        /// \param pUserHelper is the pointer to user helper object, see \link IZoomVideoSDKUserHelper \endlink.
        /// \param userList is the pointer to user object list.
        void ZoomVideoSDKDelegate::onUserLeave(IZoomVideoSDKUserHelper *pUserHelper, IVideoSDKVector<IZoomVideoSDKUser *> *userList)
        {
            if (userList)
            {
                int count = userList->GetCount();
                for (int index = 0; index < count; index++)
                {
                    IZoomVideoSDKUser *user = userList->GetItem(index);
                    if (user)
                    {
                        // RawDataFFMPEGEncoder::stop_encoding_for(user);
                    }
                }
            }
        }

