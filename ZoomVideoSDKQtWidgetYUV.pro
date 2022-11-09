QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets


CONFIG += c++17
CONFIG += staticlib

QT_DEBUG_PLUGINS = 1

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    OpenCVObjectDetect.cpp \
    OpenGLDisplay.cpp \
    main.cpp \
    opencvtextrecognition.cpp \
    widget.cpp \
    yuvpipe.cpp \
    zoomvideosdkdelegate.cpp

HEADERS += \
    OpenCVObjectDetect.h \
    OpenGLDisplay.h \
    opencvtextrecognition.h \
    widget.h \
    yuvpipe.h \
    zoomvideosdkdelegate.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#unix:!macx: LIBS += -L$$PWD/lib/zoom_video_sdk/ -lvideosdk

#INCLUDEPATH += $$PWD/lib/zoom_video_sdk/header
#DEPENDPATH += $$PWD/lib/zoom_video_sdk


# unix:!macx: LIBS += -lopencv_core
unix:!macx: LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_core
unix:!macx: LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_imgproc
unix:!macx: LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_imgcodecs
unix:!macx: LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_objdetect

INCLUDEPATH += $$PWD/../../../../usr/local/include/opencv4
DEPENDPATH += $$PWD/../../../../usr/local/include/opencv4

DISTFILES += \
    dog.xml \
     dog.xml \
    haarcascade_eye_tree_eyeglasses.xml \
    haarcascade_frontalcatface.xml \
    haarcascade_frontalface_default.xml \
    haarcascade_mcs_lefteye.xml \
    lbpcascade_silverware.xml

#install_it.path = %{buildDir}
#install_it.files += %{sourceDir}/haarcascade_frontalface_default.xml

#INSTALLS += install_it


unix:!macx: LIBS += -L$$PWD/lib/zoom_video_sdk/ -lvideosdk

INCLUDEPATH += $$PWD/lib/zoom_video_sdk/header
DEPENDPATH += $$PWD/lib/zoom_video_sdk/header
