#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->btn_scroll,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_tab,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btn_tool,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
}

Widget::~Widget()
{
    delete ui;
}
