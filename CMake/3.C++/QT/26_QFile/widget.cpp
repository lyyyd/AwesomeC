#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选择文件按钮，弹出文件对话框，读取文件长恨歌，文件路径放入到lineEdit中，将文件内容读取到textEdit中
    connect(ui->pushButton,&QPushButton::clicked,[=](){
         QString filePath = QFileDialog::getOpenFileName(this,"打开文件","E:\\BoXueGuQt","(*.txt)");

         if(filePath.isEmpty())
         {
            QMessageBox::warning(this,"警告","路径不能为空");
         }
         else
         {
             ui->lineEdit->setText(filePath);

             //指定编码格式
             QTextCodec *codec = QTextCodec::codecForName("gbk");

             //读取文件
             QFile file(filePath);
             //指定打开方式
             file.open(QIODevice::ReadOnly);

             QByteArray arr;
             //arr = file.readAll();  //读取文件所有信息

             //按行读取文件
             while(!file.atEnd())
             {
                 arr += file.readLine();
             }

             ui->textEdit->setText(codec->toUnicode(arr));

             //关闭文件
             file.close();

             //写文件
//             file.open(QFileDevice::Append);
//             file.write("你好");
//             file.close();

             QFileInfo info(filePath);
             qDebug() << "文件名： " << info.fileName() << "文件路径： " << info.filePath()
                      << "后缀名： " << info.suffix() << "文件大小： " << info.size();

             qDebug() << "创建日期： " << info.created().toString("yyyy-MM-dd hh:mm:ss")
                      << "最后修改日期： " << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");

         }
    });

    //QTextStream 文件读写
    //写文件
//    QFile file("../26_QFile/textStream.txt");
//    file.open(QFileDevice::WriteOnly);
//    QTextStream stream(&file);
//    stream << QString("hello Qt") << 1234567;
//    file.close();

    //读文件
//    file.open(QFileDevice::ReadOnly);
//    QTextStream stream(&file);
//    QString str;
//    //stream >> str;
//    str = stream.readAll();
//    qDebug() << str;

    //QDataStream 文件读写
    //写文件
    QFile file("../26_QFile/dataStream.txt");
//    file.open(QFileDevice::WriteOnly);
//    QDataStream stream(&file);
//    stream << QString("hello Qt") << 1234567;
//    file.close();

    file.open(QFileDevice::ReadOnly);
    QString str;
    int num;
    QDataStream stream(&file);
    stream >> str >> num;
    qDebug() << str << num;
    file.close();
}

Widget::~Widget()
{
    delete ui;
}
