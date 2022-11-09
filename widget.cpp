#include "widget.h"
#include "OpenGLDisplay.h"
#include "qboxlayout.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();
    setLayout(layout);
    this->resize(960,round(540*1.05));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addDisplay(OpenGLDisplay* display){
    //display->InitDrawBuffer(320*180*3/2);
    layout->addWidget(display);
}
