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

    //设置画笔
    QPen pen(QColor(255,0,0));
    pen.setWidth(2);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    //设置画刷
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::Dense4Pattern);
    painter.setBrush(brush);

    //点
    painter.drawPoint(100,30);
    //线
    painter.drawLine(QPoint(0,0),QPoint(100,100));
    //圆
    painter.drawEllipse(QPoint(100,100),50,50);
    //矩形
    painter.drawRect(QRect(20,20,50,50));
    //文字
    painter.setFont(QFont("黑体",20));
    painter.drawText(QRect(0,200,150,100),"好好学习，天天向上");
}
