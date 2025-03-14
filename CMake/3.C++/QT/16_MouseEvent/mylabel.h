#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    //重新鼠标按下、释放、移动事件
    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);

    void mouseMoveEvent(QMouseEvent *ev);

signals:

public slots:
};

#endif // MYLABEL_H
