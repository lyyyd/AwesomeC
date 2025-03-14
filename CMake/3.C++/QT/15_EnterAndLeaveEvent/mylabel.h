#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    //鼠标进入
    void enterEvent(QEvent *event);
    //鼠标离开
    void leaveEvent(QEvent *event);

signals:

public slots:
};

#endif // MYLABEL_H
