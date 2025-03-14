#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);

    //重载构造函数
    MyCoin(QString btnImg); //参数代表显示硬币的路径

    //x坐标
    int posX;
    //y坐标
    int posY;
    //正反标志
    bool flag;

    //改变标志，执行翻转效果
    void changeFlag();
    //金币翻银币 定时器
    QTimer * timer1;
    //银币翻金币 定时器
    QTimer * timer2;
    //最小图片下标值
    int min = 1;
    //最大图片下标值
    int max = 8;

    //是否正在做动画的标志
    bool isAnimation = false;

    //游戏胜利的标志
    bool isWin = false;

    //鼠标按下事件
    void mousePressEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYCOIN_H
