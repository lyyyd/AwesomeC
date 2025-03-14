#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置 窗口尺寸
    resize(600,400);

    //菜单栏 只能有1个
    QMenuBar * bar = menuBar();
    //将菜单栏设置到窗口中
    this->setMenuBar(bar);
    //添加菜单
    QMenu * fileMenu =  bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");
    //添加菜单项
    QAction * newAction  = fileMenu->addAction("新建");
    //添加分割线
    fileMenu->addSeparator();
    QAction * openAction = fileMenu->addAction("打开");

    //添加子菜单
    QMenu * subMenu = new QMenu;
    subMenu->addAction("子菜单1");
    subMenu->addAction("子菜单2");
    newAction->setMenu(subMenu);

    //工具栏 可以有多个
    QToolBar * toolBar = new QToolBar(this);
    //将工具栏添加到窗口中
    this->addToolBar( Qt::LeftToolBarArea, toolBar);
    //设置停靠区域
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动
    toolBar->setMovable(false);
    //添加工具按钮
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction("工具按钮");


    //状态栏 只能有1个
    QStatusBar * sBar = statusBar();
    //设置状态栏到窗口中
    this->setStatusBar(sBar);

    //添加文本标签
    QLabel * l1 = new QLabel("左侧信息1",this);
    sBar->addWidget(l1);

    QLabel * l2 = new QLabel("右侧信息1",this);
    sBar->addPermanentWidget(l2);

    QLabel * l3 = new QLabel("左侧信息2",this);
    sBar->insertWidget(0,l3);

    //铆接部件  可以多个（浮动窗口）
    QDockWidget * dock = new QDockWidget("浮动窗口",this);
    //添加到窗口中
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    //设置停靠范围
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    //核心部件 只能一个
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{

}
