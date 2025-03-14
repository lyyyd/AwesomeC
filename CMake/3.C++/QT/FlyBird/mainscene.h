#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "bird.h"
#include <QTimer>
#include <QDesktopWidget>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();

    Bird * m_Bird; //鸟对象的指针

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    //自动移动的位置
    QPoint m_Auto_Pos;

    //自动移动定时器
    QTimer * timer;
};

#endif // MAINSCENE_H
