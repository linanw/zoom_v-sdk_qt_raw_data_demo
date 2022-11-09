#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "OpenGLDisplay.h"
#include "zoom_video_sdk_def.h"
#include "zoom_video_sdk_interface.h"

USING_ZOOM_VIDEO_SDK_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    IZoomVideoSDK* video_sdk_obj;
    QLayout* layout;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void addDisplay(OpenGLDisplay* display);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
