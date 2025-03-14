#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //自定义槽 写到 public slots 或 public  或 全局函数 或 lambda
    //1、返回值void
    //2、需要声明，必须有实现
    //3、可以有参数，可以发生函数重载
    void treat();
    void treat(QString foodName);
};

#endif // STUDENT_H
