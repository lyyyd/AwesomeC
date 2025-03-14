#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    //this->setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下了，x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标释放了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }

}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标移动了, x = %1, y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}
