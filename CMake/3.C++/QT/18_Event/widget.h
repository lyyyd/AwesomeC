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


    //2、重写事件过滤器
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
