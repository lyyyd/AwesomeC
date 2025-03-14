#include "widget.h"
#include "ui_widget.h"
#include <QBitmap>
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
    QBitmap bit1(":/Image/butterfly.png");
    QBitmap bit2(":/Image/butterfly1.png");

    QPainter painter(this);
    painter.drawPixmap(0,50,bit1);
    painter.drawPixmap(200,50,bit2);
}
