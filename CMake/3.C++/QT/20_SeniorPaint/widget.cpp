#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

//    painter.drawEllipse(QPoint(100,100),50,50);
//    // 设置抗锯齿效果，效率低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(250,100),50,50);

    //画家设置
    painter.drawRect(QRect(20,20,50,50));
    painter.translate(100,0);
    painter.drawRect(QRect(20,20,50,50));
    //保存画家状态
    painter.save();

    painter.translate(100,0);
    //恢复画家状态
    painter.restore();
    painter.drawRect(QRect(20,20,50,50));
}
