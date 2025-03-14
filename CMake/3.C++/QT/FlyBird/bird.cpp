#include "bird.h"

Bird::Bird(QWidget *parent) : QWidget(parent)
{
    //加载所有图片
    for(int i = 0 ; i < this->max;i++)
    {
        QString str = QString(":/Bird/bird%1.png").arg(i+1);
        this->m_bird_Pix.load(str);
    }
    //设置鸟的大小
    this->setFixedSize(this->m_bird_Pix.width(),this->m_bird_Pix.height());

    //创建定时器
    this->timer = new QTimer(this);

    //监听定时器
    connect(timer,&QTimer::timeout,[=](){
        QString str = QString(":/Bird/bird%1.png").arg(this->min++);
        this->m_bird_Pix.load(str);
        if(this->min > this->max)
        {
            this->min = 1;
        }
        emit changePix(); //告诉窗口正在做切图
    });

    //创建菜单
    this->m_Menu = new QMenu();
    //监听菜单下的退出菜单项
    connect(this->m_Menu->addAction("退出"),&QAction::triggered,[=](){
        exit(0);
    });
}

void Bird::running()
{
    this->timer->start(70);
}

void Bird::mousePressEvent(QMouseEvent *event)
{
    this->m_Pos = event->globalPos() -   ((QWidget *) (this->parent()))->frameGeometry().topLeft();
    this->mouseDown = true; //鼠标按下，将状态改为true

    //右键菜单弹出
    if(event->button() == Qt::RightButton)
    {
        this->m_Menu->popup(QCursor::pos());
    }

    //窗口消失后 重置鼠标按下状态
    connect(this->m_Menu,&QMenu::aboutToHide,[=](){
        this->mouseDown = false;
    });
}

void Bird::mouseMoveEvent(QMouseEvent *event)
{
    //发送自定义信号，告诉窗口移动的位置
    emit this->moving( event->globalPos() - this->m_Pos );
}

void Bird::mouseReleaseEvent(QMouseEvent *event)
{
    //鼠标释放 ，视为鼠标没有按下
    this->mouseDown = false;
}
