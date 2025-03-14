#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QImage做绘图 设备  专门为像素级的访问做了优化
    QImage img(300,300,QImage::Format_RGB32);
    img.fill(Qt::white);
    QPainter painter(&img);
    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(QPoint(150,150),100,100);
    img.save("E:/BoXueGuQt/24_QImage/img.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage img;
    img.load(":/Image/Luffy.png");

    for(int i = 50;i < 100;i++)
    {
        for(int j = 50;j<100;j++)
        {
            QRgb val = img.pixel(j,i);
            //QRgb val = qRgb(255,0,0);
            img.setPixel(i,j,val);
        }
    }

    painter.drawImage(50,0,img);

}
