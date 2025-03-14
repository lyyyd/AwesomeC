#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    //维护选择关卡场景的对象的指针
    ChooseLevelScene * chooseScene;

private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
