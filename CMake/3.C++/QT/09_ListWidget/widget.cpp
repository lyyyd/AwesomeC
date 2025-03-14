#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建列表项
//    QListWidgetItem * item = new QListWidgetItem("床前明月光");
//    //设置文本对齐方式
//    item->setTextAlignment(Qt::AlignHCenter);
//    ui->listWidget->addItem(item);

    //添加多个列表项
    QStringList list;
    list << "床前明月光" << "疑是地上霜" << "举头望明月" << "低头思故乡";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
