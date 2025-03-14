#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret =  pix.load(normalImgPath);
    if(!ret)
    {
        qDebug() << "图片加载失败，路径为： " << normalImgPath;
        return;
    }
    //设置图片固定尺寸
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置动画时间
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置动画时间
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    //如果按下的图片路径参数不为空，代表需要切图
    if(this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            QString str = QString("图标加载失败，失败路径为：%1").arg(this->pressImgPath);
            qDebug() << str;
            return;
        }
        //设置图片固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //其他事情交给父类
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    //如果按下的图片路径参数不为空，代表需要切图
    if(this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            QString str = QString("图标加载失败，失败路径为：%1").arg(this->normalImgPath);
            qDebug() << str;
            return;
        }
        //设置图片固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //其他事情交给父类
    QPushButton::mouseReleaseEvent(e);
}
