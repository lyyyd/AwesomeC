#include "mywidget.h"
#include <QPushButton>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

//    //点击按钮关闭窗口
//    QPushButton * btn = new QPushButton("关闭窗口",this);

//    //信号槽的连接
//    //1、信号的发送者，2、发送的信号(地址) 3、信号的接受者  4、处理的槽函数(地址)
//    connect(btn,&QPushButton::clicked,this,&MyWidget::close);

//    //设置窗口尺寸
//    this->setFixedSize(600,400);

    //自定义信号和槽案例，放学后，老师发送饿了的信号，学生响应，并请老师吃饭
    //创建老师和学生
    this->te = new Teacher(this);
    this->st = new Student(this);
    //连接自定义信号和槽
//    connect(this->te,&Teacher::hungry,this->st,&Student::treat);


    //连接带参数的信号和槽
    //利用函数指针 指向 函数地址
//    void(Teacher:: * teSignal)(QString) = &Teacher::hungry;
//    void(Student:: * stSlot)(QString) = &Student::treat;

//    connect(this->te,teSignal,this->st,stSlot);
    //调用放学函数
    //this->classOver();

    //点击按钮 实现信号和信号的连接
    void(Teacher:: * teSignal2)() = &Teacher::hungry;
    void(Student:: * stSlot2)() = &Student::treat;
    connect(this->te,teSignal2,this->st,stSlot2);
    QPushButton * btn = new QPushButton;
    btn->setText("放学");
    btn->setParent(this);
    connect(btn,&QPushButton::clicked,this->te,teSignal2);

    //断开信号和槽
    disconnect(this->te,teSignal2,this->st,stSlot2);

    //其他拓展
    //多个信号可以连接到同一个槽函数中
    //一个信号可以连接多个槽函数
    //信号和槽的参数类型必须一一对应
    //信号的个数可以大于等于槽函数，但是类型必须对应

    //Qt4版本的信号和槽
    //优点：参数直观，写法简单
    //缺点：编译器不检测参数类型
    connect(this->te,SIGNAL(hungry(QString)),this->st,SLOT(treat(QString)));
    this->classOver();

    //lambda表达式
    // [=] () mutable -> {}

    QPushButton * btn2 = new QPushButton;
    btn2->move(0,100);
    btn2->setParent(this);
    btn2->setText("aaa");
    [=](){ btn2->setText("bbb");}();

    //mutable 可以修改按照值传递的拷贝
    QPushButton * btn3 =  new QPushButton;
    btn3->move(0,150);
    btn3->setParent(this);
    btn3->setText("aaa");
    QPushButton * btn4 =  new QPushButton;
    btn4->move(0,200);
    btn4->setParent(this);
    btn4->setText("ccc");

    int num = 10;
    connect(btn3,&QPushButton::clicked,this,[=]() mutable {
        num = 20;
        qDebug() << num;
    });
    connect(btn4,&QPushButton::clicked,this,[=]() mutable {
        qDebug() << num;
    });

    //返回值
    int num2 = []()->int{return 1000;}();
    qDebug() << num2;

    //推荐使用 [=](){}
    QPushButton * btn5 =  new QPushButton;
    btn5->move(0,250);
    btn5->setParent(this);
    btn5->setText("ddd");
    connect(btn5,&QPushButton::clicked,[=](){
       btn5->setText("eee");
    });
}

//放学
void MyWidget::classOver()
{
    //触发自定义信号
    emit this->te->hungry("宫保鸡丁");
}

MyWidget::~MyWidget()
{

}
