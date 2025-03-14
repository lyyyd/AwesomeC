#include "mainscene.h"
#include <QPainter>
#include <QApplication>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{

    //实例化鸟对象
    this->m_Bird = new Bird;
    //将鸟对象设置到窗口中
    this->m_Bird->setParent(this);

    //设置窗口尺寸
    this->setFixedSize(this->m_Bird->width(),this->m_Bird->height());

    //启动定时器
    this->m_Bird->running();

    //监听鸟切图的信号，并且重新绘图
    connect(this->m_Bird,&Bird::changePix,[=](){
        update();
    });

    //监听鸟移动的信号，并且移动相应的位置
    connect(this->m_Bird, &Bird::moving,[=](QPoint point){

            this->move(point);

            this->m_Auto_Pos = point; //鼠标拖拽后的位置实时更新
    });

    //获取屏幕信息
    QDesktopWidget * desk = QApplication::desktop();

    //创建定时器
    this->timer = new QTimer(this);
    //开启定时器
    this->timer->start(30);
    //监听定时器
    connect(timer,&QTimer::timeout,[=](){
        //如果鼠标没有按下，鸟自动移动，鼠标按下时候不要移动
        if(this->m_Bird->mouseDown != true)
        {
            this->m_Auto_Pos.setX(this->m_Auto_Pos.x() + 5);
        }

        if(this->m_Auto_Pos.x() > desk->width())
        {
            this->m_Auto_Pos.setX(-this->width());
        }
        this->move(this->m_Auto_Pos);
    });

    //去除标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);

    //设置透明窗体  120号属性
    this->setAttribute(Qt::WA_TranslucentBackground);

    //窗口设置到顶层
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    //设置起始Y坐标
    this->m_Auto_Pos.setY(desk->height() * 0.5 -  this->m_Bird->height());
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,this->m_Bird->m_bird_Pix);
}


MainScene::~MainScene()
{

}
