#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("保时捷");

    //点击宝马按钮发送的信号
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("宝马");
    });

    //利用QLabel显示图片
    ui->lbl_pic->setPixmap(QPixmap(":/Image/butterfly.png"));

    //利用QLabel显示动图  gif
    QMovie * movie = new QMovie(":/Image/mario.gif");
    ui->lbl_movie->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}
