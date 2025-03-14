#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入了";
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开了";
}
