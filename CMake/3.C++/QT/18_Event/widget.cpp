#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1、给控件安装过滤器
    ui->label->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent*>(event);
        QString str = QString("在eventFilter事件过滤器中，鼠标按下了 ， x = %1 , y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        return true; //拦截事件 不在向下分发
    }
    //其余的控件和事件交给父类处理
    return QWidget::eventFilter(watched,event);
}
