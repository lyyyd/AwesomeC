#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    QString str = QString("鼠标按下了 ， x = %1 , y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
}

bool MyLabel::event(QEvent *e)
{
    if(e->type() ==  QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent*>(e);
        QString str = QString("在event事件分发器中，鼠标按下了 ， x = %1 , y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        return true; //拦截事件 不在向下分发
    }
    //其他事件交给父类处理
    return QLabel::event(e);
}
