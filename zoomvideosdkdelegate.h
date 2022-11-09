#ifndef ZOOMVIDEOSDKDELEGATE_H
#define ZOOMVIDEOSDKDELEGATE_H

#include "helpers/zoom_video_sdk_user_helper_interface.h"
#include "qguiapplication.h"
#include "widget.h"
#include "yuvpipe.h"
#include "zoom_video_sdk_def.h"
#include "zoom_video_sdk_delegate_interface.h"

USING_ZOOM_VIDEO_SDK_NAMESPACE

class ZoomVideoSDKDelegate : public IZoomVideoSDKDelegate
{
//    QGuiApplication* app_;
    Widget* widget_;

public:
    ZoomVideoSDKDelegate(Widget* widget);
    ~ZoomVideoSDKDelegate();
    virtual  void onSessionJoin();
    virtual void onSessionLeave();
    virtual void onError(ZoomVideoSDKErrors errorCode, int detailErrorCode);
    virtual void onUserJoin(IZoomVideoSDKUserHelper *pUserHelper, IVideoSDKVector<IZoomVideoSDKUser *> *userList);
    virtual void onUserLeave(IZoomVideoSDKUserHelper *pUserHelper, IVideoSDKVector<IZoomVideoSDKUser *> *userList);
    /// \brief Triggered when user video status changed.
        /// \param pVideoHelper is the pointer to video helper object, see \link IZoomVideoSDKVideoHelper \endlink.
        /// \param userList is the pointer to user object list.
        virtual void onUserVideoStatusChanged(IZoomVideoSDKVideoHelper *pVideoHelper,
                                              IVideoSDKVector<IZoomVideoSDKUser *> *userList){};

        /// \brief Triggered when user audio status changed.
        /// \param pAudioHelper is the pointer to audio helper object, see \link IZoomVideoSDKAudioHelper \endlink.
        /// \param userList is the pointer to user object list.
        virtual void onUserAudioStatusChanged(IZoomVideoSDKAudioHelper *pAudioHelper,
                                              IVideoSDKVector<IZoomVideoSDKUser *> *userList){};

        /// \brief Triggered when user Share status changed.
        /// \param pShareHelper is the pointer to share helper object, see \link IZoomVideoSDKShareHelper \endlink.
        /// \param pUser is the pointer to user object.
        /// \param status is the share status of the user.
        virtual void onUserShareStatusChanged(IZoomVideoSDKShareHelper *pShareHelper,
                                              IZoomVideoSDKUser *pUser,
                                              ZoomVideoSDKShareStatus status){};

        /// \brief Triggered when user live stream status changed
        /// \param pLiveStreamHelper is the pointer to live stream helper object, see \link IZoomVideoSDKLiveStreamHelper
        /// \endlink. \param status is the current status of live stream.
        virtual void onLiveStreamStatusChanged(IZoomVideoSDKLiveStreamHelper *pLiveStreamHelper,
                                               ZoomVideoSDKLiveStreamStatus status){};

        /// \brief Triggered when chat message received.
        /// \param pChatHelper is the pointer to chat helper object, see \link IZoomVideoSDKChatHelper \endlink.
        /// \param messageItem is the pointer to message object
        virtual void onChatNewMessageNotify(IZoomVideoSDKChatHelper *pChatHelper, IZoomVideoSDKChatMessage *messageItem){};

        /// \brief Triggered when host changed.
        /// \param pUserHelper is the pointer to user helper object, see \link IZoomVideoSDKUserHelper \endlink.
        /// \param pUser is the pointer to user object.
        virtual void onUserHostChanged(IZoomVideoSDKUserHelper *pUserHelper, IZoomVideoSDKUser *pUser){};

        /// \brief Triggered when active audio user changed.
        /// \param pAudioHelper is the pointer to audio helper object, see \link IZoomVideoSDKAudioHelper \endlink.
        /// \param list is the pointer to user object list.
        virtual void onUserActiveAudioChanged(IZoomVideoSDKAudioHelper *pAudioHelper,
                                              IVideoSDKVector<IZoomVideoSDKUser *> *list){};

        /// \brief Triggered when session needs password.
        /// \param handler is the pointer to password handler object, see \link IZoomVideoSDKPasswordHandler \endlink.
        virtual void onSessionNeedPassword(IZoomVideoSDKPasswordHandler *handler){};

        /// \brief Triggered when password is wrong.
        /// \param handler is the pointer to password handler object, see \link IZoomVideoSDKPasswordHandler \endlink.
        virtual void onSessionPasswordWrong(IZoomVideoSDKPasswordHandler *handler){};

        /// \brief Triggered when mixed audio raw data received.
        /// \param data_ is the pointer to audio raw data, see \link AudioRawData \endlink.
        virtual void onMixedAudioRawDataReceived(AudioRawData *data_){};

        /// \brief Triggered when one way audio raw data received.
        /// \param data_ is the pointer to audio raw data, see \link AudioRawData \endlink.
        /// \param pUser is the pointer to user object, see \link IZoomVideoSDKUser \endlink.
        virtual void onOneWayAudioRawDataReceived(AudioRawData *data_, IZoomVideoSDKUser *pUser){};

        /// \brief Triggered when share audio data received.
        /// \param data_ is the pointer to audio raw data, see \link AudioRawData \endlink.
        virtual void onSharedAudioRawDataReceived(AudioRawData *data_){};

        /// \brief Triggered when user get session manager role.
        /// \param pUser is the pointer to user object, see \link IZoomVideoSDKUser \endlink.
        virtual void onUserManagerChanged(IZoomVideoSDKUser *pUser){};

        /// \brief Triggered when user name changed.
        /// \param pUser is the pointer to user object, see \link IZoomVideoSDKUser \endlink.
        virtual void onUserNameChanged(IZoomVideoSDKUser *pUser){};

        /// \brief Callback for when the current user is granted camera control access.
        /// Once the current user sends the camera control request, this callback will be triggered with the result of the
        /// request. \param pUser the pointer to the user who received the request, see \link IZoomVideoSDKUser \endlink.
        /// \param isApproved the result of the camera control request
        virtual void onCameraControlRequestResult(IZoomVideoSDKUser *pUser, bool isApproved){};

        /// \brief Callback interface for when the current user has received a camera control request.
        /// This will be triggered when another user requests control of the current user��s camera.
        /// \param pUser is the pointer to the user who sent the request, see \link IZoomVideoSDKUser \endlink.
        /// \param requestType the request type, see \link ZoomVideoSDKCameraControlRequestType \endlink.
        /// \param pCameraControlRequestHandler the pointer to the helper instance of the camera controller, see \link
        /// IZoomVideoSDKCameraControlRequestHandler \endlink.
        virtual void onCameraControlRequestReceived(
            IZoomVideoSDKUser *pUser,
            ZoomVideoSDKCameraControlRequestType requestType,
            IZoomVideoSDKCameraControlRequestHandler *pCameraControlRequestHandler){};

        /// \brief Callback for when a message has been received from the command channel.
        ///        Once the command channel is active, this callback is triggered each time a message has been received.
        /// \param pSender The user who sent the command, see \link IZoomVideoSDKUser \endlink.
        /// \param strCmd Received command.
        virtual void onCommandReceived(IZoomVideoSDKUser *sender, const zchar_t *strCmd){};

        /// \brief Callback for when the command channel is ready to be used.
        ///        After the SDK attempts to establish a connection for the command channel upon joining a session,
        ///        this callback will be triggered once the connection attempt has completed.
        /// \param isSuccess true: success, command channel is ready to be used.
        ///        false: Failure, command channel was unable to connect.
        virtual void onCommandChannelConnectResult(bool isSuccess){};

        /// \brief Triggered when call Out status changed.
        virtual void onInviteByPhoneStatus(PhoneStatus status, PhoneFailedReason reason){};

        /// \brief Callback for when the cloud recording status has changed (e.g. paused, stopped, resumed).
        /// \param status cloud recording status defined in \link RecordingStatus \endlink.
        virtual void onCloudRecordingStatus(RecordingStatus status){};

        /// \brief Triggered when host ask you to unmute.
        virtual void onHostAskUnmute(){};

        virtual void onUserShareStatusChanged(IZoomVideoSDKShareHelper *pShareHelper, IZoomVideoSDKUser *pUser, ZoomVideoSDKShareStatus status, ZoomVideoSDKShareType type) {}

        virtual void onMultiCameraStreamStatusChanged(ZoomVideoSDKMultiCameraStreamStatus status, IZoomVideoSDKUser *pUser, IZoomVideoSDKRawDataPipe *pVideoPipe) {}

        virtual void onMicSpeakerVolumeChanged(unsigned int micVolume, unsigned int speakerVolume) {}

        virtual void onAudioDeviceStatusChanged(ZoomVideoSDKAudioDeviceType type, ZoomVideoSDKAudioDeviceStatus status) {}

        virtual void onTestMicStatusChanged(ZoomVideoSDK_TESTMIC_STATUS status) {}

        virtual void onSelectedAudioDeviceChanged() {}

        virtual void onLiveTranscriptionStatus(ZoomVideoSDKLiveTranscriptionStatus status) {}

        /// \brief live transcription message received callback.
        /// \param ltMsg: an object pointer to the live transcription message content.
        /// \param pUser the pointer to the user who speak the message, see \link IZoomVideoSDKUser \endlink.
        /// \param type: the live transcription operation type. For more details, see \link ZoomVideoSDKLiveTranscriptionOperationType \endlink.
        virtual void onLiveTranscriptionMsgReceived(const zchar_t *ltMsg, IZoomVideoSDKUser *pUser, ZoomVideoSDKLiveTranscriptionOperationType type) {}

        /// \brief The translation message error callback.
        /// \param speakingLanguage: an object of the spoken message language.
        /// \param transcriptLanguageId: an object of the message language you want to translate.
        virtual void onLiveTranscriptionMsgError(ILiveTranscriptionLanguage *spokenLanguage, ILiveTranscriptionLanguage *transcriptLanguage) {}
};

#endif // ZOOMVIDEOSDKDELEGATE_H
