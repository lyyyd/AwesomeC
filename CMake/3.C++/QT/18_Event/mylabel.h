#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    //重写鼠标按下事件
    void mousePressEvent(QMouseEvent *ev);

    //重写事件分发器
    bool event(QEvent *e);
signals:

public slots:
};

#endif // MYLABEL_H
