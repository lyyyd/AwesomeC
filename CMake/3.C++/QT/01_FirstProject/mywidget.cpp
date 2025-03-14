#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

//ctrl + r	运行项目
//ctrl + b	编译项目
//ctrl + /	注释 / 取消注释
//ctrl + 鼠标滚轮	调整字体缩放
//ctrl + shift + ↑ 或 ↓	整行移动
//ctrl + i 	自动对齐
//ctrl + f	查找
//F1	帮助
//F4	同名头文件与源文件切换

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
//    //按钮控件
//    QPushButton * btn  = new QPushButton;
//    btn->setParent(this);
//    //设置文本
//    btn->setText("你好");
//    //设置尺寸
//    btn->resize(200,100);
//    //移动
//    btn->move(100,100);

//    //窗口设置尺寸
//    this->resize(600,400);

//    //设置固定尺寸
    this->setFixedSize(600,400);

//    //设置窗口标题
//    this->setWindowTitle("第一个窗口");

//    //自定义按钮
//    MyPushButton * myBtn = new MyPushButton;
//    myBtn->setParent(this);
//    myBtn->setText("我的按钮");

    QPushButton * btn1 = new QPushButton("第一个按钮",this);
    btn1->move(100,0);

    QPushButton * btn2 = new QPushButton("第二个按钮",this);
    btn2->move(0,150);

    QPushButton * btn3 = new QPushButton("第三个按钮",this);
    btn3->move(150,150);
}

MyWidget::~MyWidget()
{
    qDebug() << "myWidget的析构函数调用" ;
}
