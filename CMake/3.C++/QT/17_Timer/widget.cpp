#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    this->id1 = startTimer(1000);
    this->id2 = startTimer(2000);

    //定时器类
    QTimer * timer = new QTimer(this);
    timer->start(500);
    //监听定时器对象发送的信号
    connect(timer,&QTimer::timeout,[=](){
        static int num1 = 1;
        ui->label_3->setText(QString::number(num1++));
    });

    //点击停止按钮 停止定时器对象
    connect(ui->btn_stop,&QPushButton::clicked,[=](){
        timer->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == this->id1)
    {
        static int num1 = 1;
        ui->label->setText(QString::number(num1++));
    }

    if(event->timerId() == this->id2)
    {
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }

}
