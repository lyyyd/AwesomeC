#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    //重载构造函数
    MyPushButton(QString normalImg, QString pressImg = "");

    //成员属性 记录图片路径
    QString normalImgPath;
    QString pressImgPath;

    //向下向上跳跃动画
    void zoom1();
    void zoom2();

    //重写鼠标按下 鼠标 释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
