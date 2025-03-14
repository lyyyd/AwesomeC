#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);

    //重载构造函数
    PlayScene(int level);

    //成员变量 保存关卡号
    int levelIndex;

    //绘图事件
    void paintEvent(QPaintEvent *event);

    //记录当前关卡的二维数组
    int gameArray[4][4];

    //维护所有硬币的二维数组
    MyCoin * coinBtn[4][4];

    //游戏胜利标志
    bool isWin;

signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
