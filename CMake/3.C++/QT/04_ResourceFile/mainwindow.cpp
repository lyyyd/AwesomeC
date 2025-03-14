#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionNew->setIcon(QIcon("E:/BoXueGuQt/Image/Luffy.png"));

    //语法："：+前缀名+文件名"
    ui->actionNew->setIcon(QIcon(":/Image/OnePiece.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
