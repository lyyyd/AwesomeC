#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //重写定时器事件
    void timerEvent(QTimerEvent *event);

    //定义定时器唯一id
    int id1;
    int id2;
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
