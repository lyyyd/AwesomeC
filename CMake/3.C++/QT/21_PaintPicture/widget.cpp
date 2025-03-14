#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->posX = 0;
    //监听点击信号
    connect(ui->btn_move,&QPushButton::clicked,[=](){
        this->posX += 10;
        //手动调用绘图事件，利用update
        update();
    });

    //创建定时器对象
    QTimer * timer = new QTimer(this);
    timer->start(10);

    connect(timer,&QTimer::timeout,[=](){
        this->posX++;
        update();;
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/Image/Luffy.png");

    if(posX > this->width())
    {
        posX = -pix.width();
    }

    painter.drawPixmap(posX,0,pix);
}
