#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFontDialog>
#include <QFont>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建菜单项，弹出对话框
    connect(ui->actionNew,&QAction::triggered,[=](){
        //对话框分类：模态对话框 非模态对话框
        //模态对话框
//        QDialog dlg(this);
//        dlg.resize(200,80);
//        dlg.setWindowTitle("模态对话框");
//        dlg.exec();

        //非模态对话框
//        QDialog * dlg = new QDialog(this);
//        dlg->resize(200,80);
//        dlg->setWindowTitle("非模态对话框");
//        dlg->show();
//        //设置属性，解决堆区对话框对象释放的问题
//        dlg->setAttribute(Qt::WA_DeleteOnClose);

        //消息对话框
        //询问对话框
        //        if(QMessageBox::Save == QMessageBox::question(this,"询问对话框","是否保存",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel))
        //        {
        //            qDebug() << "选择的是保存";
        //        }
        //        else
        //        {
        //            qDebug() << "选择的是取消";
        //        }

        //QMessageBox::critical(this,"错误对话框","出错了！");

        // QMessageBox::information(this,"信息对话框","提示信息");

        //QMessageBox::warning(this,"警告对话框","警告提示！");

        //颜色对话框
//           QColor color = QColorDialog::getColor(QColor(255,0,0));
//           qDebug() <<color.red() << color.green() << color.blue();

        //文件对话框
//            QString fileName = QFileDialog::getOpenFileName(this,"文件对话框","E:\\BoXueGuQt\\05_Dialog","(*.cpp *.h)");
//            qDebug() << fileName;

        //字体对话框
            bool ok;
            QFont font = QFontDialog::getFont(&ok);
            qDebug() << "字体： " <<font.family() << "字号： "<<font.pointSize()
                     << "加粗： "<<font.bold() << "倾斜： " << font.italic()
                     << "ok: " << ok;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
