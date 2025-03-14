#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置固定尺寸
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/CoinRes/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币游戏");
    //退出菜单项功能实现
    connect(ui->actionQuit,&QAction::triggered,[=](){this->close();});

    //开始按钮音效
    QSound * startSound = new QSound(":/CoinRes/TapButtonSound.wav",this);

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/CoinRes/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height() * 0.7 );

    //监听开始按钮的点击信号
    connect(startBtn,&MyPushButton::clicked,[=](){
        //播放音效
        startSound->play();

        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入到第二个选择关卡的场景
        QTimer::singleShot(500,this,[=](){
            this->hide();
            this->chooseScene->setGeometry(this->geometry());
            this->chooseScene->show();
        });

    });

    //创建第二个创建对象
    this->chooseScene = new ChooseLevelScene;

    //监听第二个选择关卡场景中的返回按钮发送的信号
    connect(this->chooseScene,&ChooseLevelScene::chooseSceneBack,[=](){
        this->setGeometry(this->chooseScene->geometry());
        //显示自身
        this->show();
        //隐藏第二个选择关卡场景
        this->chooseScene->hide();
    });

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    //创建画家对象 并指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    pix.load(":/CoinRes/PlayLevelSceneBg.png");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //绘制标题图
    pix.load(":/CoinRes/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
