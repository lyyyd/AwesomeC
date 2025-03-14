#include "mycoin.h"
#include <QDebug>

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        qDebug() <<"图标加载失败，失败路径为： " << btnImg;
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //创建定时器对象
    this->timer1 = new QTimer(this);
    this->timer2 = new QTimer(this);

    //监听定时器发送的信号
    connect(this->timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/CoinRes/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min > this->max)
        {
            isAnimation = false;
            this->min = 1;
            timer1->stop();
        }
    });

    connect(this->timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/CoinRes/Coin000%1.png").arg(this->max--);
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->max < this->min)
        {
            isAnimation = false;
            this->max = 8;
            timer2->stop();
        }
    });
}

void MyCoin::changeFlag()
{
    isAnimation = true;
    if(this->flag)
    {
        this->timer1->start(30);
        this->flag = false;
    }
    else
    {
        this->timer2->start(30);
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
