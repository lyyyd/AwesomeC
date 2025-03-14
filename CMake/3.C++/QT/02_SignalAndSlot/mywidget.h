#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

    Teacher * te;
    Student * st;

    //放学
    void classOver();
};

#endif // MYWIDGET_H
