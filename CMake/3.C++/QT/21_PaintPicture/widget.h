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

    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    //x坐标
    int posX;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
