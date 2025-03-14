#include "widget.h"
#include "ui_widget.h"
#include <QPicture>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPicture 做绘图设备 记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);

    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150,150),100,100);

    painter.end();

    pic.save("E:/BoXueGuQt/25_QPicture/pic.bxg");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPicture pic;
    pic.load("E:/BoXueGuQt/25_QPicture/pic.bxg");
    painter.drawPicture(0,0,pic);
}
