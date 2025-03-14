#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置头部的标签
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    //设置正文
    //设置行数
    ui->tableWidget->setRowCount(5);
    //准备数据
    QStringList nameList; //姓名列表
    QStringList sexList;  //性别列表
    nameList << "刘备" << "关羽" << "张飞" << "貂蝉" << "吕布";
    sexList << "男" << "男" << "男" << "女" << "男";

    //通过循环将所有数据设置到 tableWidget中
    for(int i = 0 ; i< 5;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(nameList.at(i)));
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i,col++, new QTableWidgetItem(QString::number(20 + i)));
    }

    //点击添加赵云按钮的信号
    connect(ui->addBtn,&QPushButton::clicked,[=](){
         //判断赵云是否为空，不为空不添加
        bool isEmpty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).isEmpty();
        if(isEmpty)
        {
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0, new QTableWidgetItem("赵云"));
            ui->tableWidget->setItem(0,1, new QTableWidgetItem("男"));
            ui->tableWidget->setItem(0,2, new QTableWidgetItem("19"));
        }
        else
        {
            QMessageBox::warning(this,"Warning","赵云已经存在,添加失败");
        }
    });

    //点击删除赵云按钮的信号
    connect(ui->delBtn,&QPushButton::clicked,[=](){
        //如果没有赵云，则不做任何操作
        bool isEmpty = ui->tableWidget->findItems("赵云",Qt::MatchExactly).isEmpty();
        if(isEmpty)
        {
           QMessageBox::warning(this,"Warning","赵云不存在,删除失败");
        }
        else
        {
            //找到赵云所在行
            int rowNum = ui->tableWidget->findItems("赵云",Qt::MatchExactly).first()->row();
            ui->tableWidget->removeRow(rowNum);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
