#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //默认选中男
    ui->rBtnMan->setChecked(true);

    //如果 选中女 ，输出相应文字
    connect(ui->rBtnWomen,&QRadioButton::clicked,[=](){
        qDebug() << "选中女";
    });

    //判断用户是否选中了环境优雅
    connect(ui->checkBox,&QCheckBox::stateChanged,[=](int state){
        if(state == 2)
        {
            qDebug() << "选中了环境优雅";
        }
        else if(state == 0)
        {
            qDebug() << "未选中了环境优雅";
        }
        else
        {
            qDebug() << "半选中了环境优雅";
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
