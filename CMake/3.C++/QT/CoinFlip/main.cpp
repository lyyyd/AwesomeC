#include "mainscene.h"
#include <QApplication>
#include "chooselevelscene.h"
#include "dataconfig.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ChooseLevelScene w;
    MainScene w;
    w.show();

    //测试第一个关的数据
//    dataConfig config;
//    for(int i = 0 ; i < 4;i++)
//    {
//        for(int j = 0 ; j < 4;j++)
//        {
//            qDebug() << config.mData[1][i][j] ;
//        }
//        qDebug() << "";
//    }


    return a.exec();
}
