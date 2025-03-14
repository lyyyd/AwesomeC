#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <functional>
#include <deque>
#include <numeric>
#include <fstream>

//演讲比赛管理类
class SpeechManager
{
public:

    //构造函数
    SpeechManager();

    //展示菜单
    void show_Menu();

    //退出程序
    void exitSystem();

    //初始化容器
    void initSpeech();

    //创建比赛选手
    void createSpeaker();

    //控制比赛流程  开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示比赛结果
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();

    //展示记录
    void showRecord();

    //清空记录
    void clearRecord();

    //文件是否为空标志
    bool fileIsEmpty; //true为空 false非空

    //记录往届分数的容器  key代表第几届  value代表具体信息
    map<int, vector<string>> m_Record;

    //析构函数
    ~SpeechManager();

    //成员属性  存放选手容器
    vector<int>v1; //第一轮比赛选手编号

    vector<int>v2; //第二轮比赛选手编号

    vector<int>vVictory; //前三名 选手编号

    //存放编号以及对应选手容器
    map<int, Speaker> m_Speaker;

    //记录比赛轮数
    int m_Index;
};