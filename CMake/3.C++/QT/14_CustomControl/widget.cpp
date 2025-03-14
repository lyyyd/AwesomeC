#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击获取值 监听信号
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug() <<  ui->widget->getData();
    });

    //点击设置到一半 监听信号
    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setData(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
