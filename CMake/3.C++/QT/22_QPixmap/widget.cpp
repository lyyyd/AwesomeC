#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Pixmap作为绘图设备，对不同平台做了显示优化
    QPixmap pix(300,300);
    pix.fill(Qt::white);
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150,150),100,100);
    pix.save("E:\\BoXueGuQt\\22_QPixmap\\pix.png");
}

Widget::~Widget()
{
    delete ui;
}
