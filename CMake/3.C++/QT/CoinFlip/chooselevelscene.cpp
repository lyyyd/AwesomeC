#include "chooselevelscene.h"
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置窗口固定尺寸
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/CoinRes/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡");

    //选关按钮音效
    QSound * chooseSound = new QSound(":/CoinRes/TapButtonSound.wav",this);
    //返回按钮音效
    QSound * backSound = new QSound(":/CoinRes/BackButtonSound.wav",this);

    //创建菜单栏
    QMenuBar * bar =  menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    //创建退出菜单项
    QAction * quitAction =  startMenu->addAction("退出");
    //监听退出菜单项
    connect(quitAction,&QAction::triggered,[=](){ this->close(); });

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/CoinRes/BackButton.png",":/CoinRes/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height() - backBtn->height());

    //监听返回按钮点击
    connect(backBtn,&MyPushButton::clicked,[=](){
        backSound->play();
        QTimer::singleShot(500,[=](){
            //延时 返回主场景，发送自定义信号
            emit this->chooseSceneBack();
        });
    });


    //创建选择关卡按钮
    for(int i = 0 ; i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/CoinRes/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move( 25 + (i%4)*70 , 130 + (i/4)*70 );
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //qDebug() << "您选择的是第" << i + 1 << "关" ;
            //播放音效
            chooseSound->play();
            if(this->pScene == NULL)
            {
                this->hide();
                this->pScene = new PlayScene(i+1);
                this->pScene->setGeometry(this->geometry());
                this->pScene->show();

                connect(pScene,&PlayScene::chooseSceneBack,[=](){
                    this->setGeometry(this->pScene->geometry());
                    this->show();
                    delete this->pScene;
                    this->pScene = NULL;
                });
            }
        });

        //显示按钮上的文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText( QString::number( i+1 ));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->move(25 + (i%4)*70 , 130 + (i/4)*70);
        //设置属性 鼠标穿透属性  51
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/CoinRes/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/CoinRes/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);
}
