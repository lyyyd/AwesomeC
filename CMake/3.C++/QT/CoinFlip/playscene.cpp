#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSound>

PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}

PlayScene::PlayScene(int level)
{
    qDebug() << "当前关卡为： " << level;
    this->levelIndex = level;

    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/CoinRes/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");

    //返回按钮音效
    QSound * backSound = new QSound(":/CoinRes/BackButtonSound.wav",this);

    //点击硬币的音效
    QSound * flipSound = new QSound(":/CoinRes/ConFlipSound.wav",this);

    //游戏胜利的音效
    QSound * winSound = new QSound(":/CoinRes/LevelWinSound.wav",this);

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu * startMenu = bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction,&QAction::triggered,[=](){this->close();});

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/CoinRes/BackButton.png",":/CoinRes/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(),this->height() - backBtn->height());

    //点击返回按钮 触发自定义信号
    connect(backBtn,&MyPushButton::clicked,[=](){
        backSound->play();
        QTimer::singleShot(500,[=](){
            this->hide();
            //触发信号
            emit this->chooseSceneBack();
        });
    });

    //显示当前关卡号
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("黑体");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Level:%1").arg(this->levelIndex);
    label->setText(str);
    label->setGeometry(QRect(30,this->height() - 50,this->width(),50));
    label->setAttribute(Qt::WA_TransparentForMouseEvents);

    //初始化二维数组
    dataConfig config;
    for(int i = 0 ; i< 4;i++)
    {
        for(int j = 0 ; j < 4;j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利动画图片
    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/CoinRes/LevelCompletedDialogBg.png");
    winLabel->setPixmap(tmpPix);
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setParent(this);
    winLabel->move(this->width()*0.5 - tmpPix.width()*0.5, -tmpPix.height());

    //创建硬币背景图片和硬币对象
    for(int i = 0 ; i< 4;i++)
    {
        for(int j = 0 ; j < 4;j++)
        {
            //硬币背景图
            QLabel * bg = new QLabel;
            bg->setGeometry(0,0,50,50);
            bg->setPixmap(QPixmap(":/CoinRes/BoardNode.png"));
            bg->setParent(this);
            bg->move(57+i*50,200+j*50);

            //硬币对象
            QString img;
            if(this->gameArray[i][j] == 1)
            {
                img = ":/CoinRes/Coin0001.png";
            }
            else
            {
                img = ":/CoinRes/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);
            //硬币的属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];

            this->coinBtn[i][j] = coin;

            //监听硬币的点击
            connect(coin,&MyCoin::clicked,[=](){
                //禁用所有硬币点击
                for(int i = 0 ; i < 4;i++)
                {
                    for(int j = 0 ; j < 4;j++)
                    {
                        this->coinBtn[i][j]->isWin = true;
                    }
                }
                flipSound->play();
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;
                //延时翻转周围硬币
                QTimer::singleShot(300,[=](){
                    if(coin->posX + 1 <= 3)  //检测右侧硬币
                    {
                        this->coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posX - 1 >= 0)  //检测左侧硬币
                    {
                        this->coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posY + 1 <= 3)  //检测下侧硬币
                    {
                        this->coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0;
                    }
                    if(coin->posY - 1 >= 0 )  //检测上侧硬币
                    {
                        this->coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0;
                    }

                    //检测游戏胜利
                    this->isWin = true;
                    for(int i = 0 ; i < 4;i++)
                    {
                        for(int j = 0 ; j < 4;j++)
                        {
                            if(this->coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                        if(this->isWin ==  false)
                        {
                            break;
                        }
                    }
                    if(this->isWin)
                    {
                        qDebug() << "游戏胜利";
                        winSound->play();
                        QPropertyAnimation * animation = new QPropertyAnimation(winLabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y() + 114,winLabel->width(),winLabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start(QAbstractAnimation::DeleteWhenStopped);
                        //将所有硬币的isWin设置为true，代表禁用效果
                        for(int i = 0 ; i < 4;i++)
                        {
                            for(int j = 0 ; j < 4;j++)
                            {
                                this->coinBtn[i][j]->isWin = true;
                            }
                        }
                    }
                    else
                    {
                        for(int i = 0 ; i < 4;i++)
                        {
                            for(int j = 0 ; j < 4;j++)
                            {
                                this->coinBtn[i][j]->isWin = false;
                            }
                        }
                    }
                });
            });
        }
    }
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/CoinRes/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //绘制标题图
    pix.load(":/CoinRes/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
