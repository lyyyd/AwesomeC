#ifndef BIRD_H
#define BIRD_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QMenu>

class Bird : public QWidget
{
    Q_OBJECT
public:
    explicit Bird(QWidget *parent = nullptr);

    QPixmap m_bird_Pix; //显示鸟的图片

    int min = 1; //显示鸟的图片的最小下标
    int max = 8; //显示鸟的图片的最大下标

    //定时器
    QTimer * timer;

    //执行动画的函数
    void running();

    //记录坐标的分量
    QPoint m_Pos;

    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);

    //鼠标按下状态
    bool mouseDown = false;

    //创建菜单
    QMenu * m_Menu;

signals:
    //自定义信号，告诉窗口鸟正在做切图
    void changePix();
    //发送自定义信号，告诉窗口移动的位置
    void moving(QPoint point);
public slots:
};

#endif // BIRD_H
