#include "speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
    //初始化容器和属性
    this->initSpeech();

    //创建所有比赛选手
    this->createSpeaker();

    //读取记录
    this->loadRecord();


    //测试
    //cout << this->m_Record[0][0] << endl; //第一届 冠军选手编号
    //cout << this->m_Record[0][1] << endl; //第一届 冠军选手得分
}

//展示菜单
void SpeechManager::show_Menu()
{
    cout << "**********************************" << endl;
    cout << "*******  欢迎参加演讲比赛  *******" << endl;
    cout << "*******  1.开始演讲比赛    *******" << endl;
    cout << "*******  2.查看往届记录    *******" << endl;
    cout << "*******  3.清空比赛记录    *******" << endl;
    cout << "*******  0.退出比赛程序    *******" << endl;
    cout << "**********************************" << endl;
    cout << endl;
}

//退出程序
void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}


//初始化容器
void SpeechManager::initSpeech()
{
    //容器清空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    //初始化比赛轮数
    this->m_Index = 1;

    this->m_Record.clear();
}

//创建比赛选手
void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";

    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;

        for (int j = 0; j < 2; j++)
        {
            sp.m_Score[j] = 0;
        }

        //将所有12个选手 存放到v1容器中
        this->v1.push_back(i + 10001);

        //将编号 和 对应选手 放入到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

//抽签
void SpeechManager::speechDraw()
{
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
    cout << "---------------------------" << endl;
    cout << "抽签后演讲顺序如下： " << endl;

    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << "---------------------------" << endl;
    system("pause");
    cout << endl;

}

//比赛
void SpeechManager::speechContest()
{
    cout << "-------------- 第" << this->m_Index << "轮正式比赛开始 --------------" << endl;

    multimap<double, int, greater<double>> groupScore;// 临时容器 key保存选手得分，value 选手编号

    int num = 0; //记录人员数量，每6个人为一组

    vector<int>v_Src; //比赛人员容器

    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    //遍历所有选手 进行比赛
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;

        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double  score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
            //cout << score << " ";
            d.push_back(score);
        }

        sort(d.begin(), d.end(), greater<double>()); //降序排序
        d.pop_back(); //去除最低分
        d.pop_front();//去除最高分

        double sum = accumulate(d.begin(), d.end(), (double)0.0f);
        double avg = sum / (double)d.size();  //平均分

        //将平均分赋值给选手上
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        //每6个人 用临时容器保存
        groupScore.insert(make_pair(avg, *it));

        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次： " << endl;
            for (multimap<double, int, greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
            {
                cout << "编号：" << mit->second << " 姓名： "
                     << this->m_Speaker[mit->second].m_Name << " 成绩： "
                     << this->m_Speaker[mit->second].m_Score[this->m_Index - 1] << endl;
            }

            //取前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end() && count < 3; mit++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*mit).second);
                }
                else
                {
                    vVictory.push_back((*mit).second);
                }
            }

            groupScore.clear();
            cout << endl;
        }
    }
    cout << "-------------- 第" << this->m_Index << "轮比赛完毕 --------------" << endl;
    system("pause");
}

//显示比赛结果
void SpeechManager::showScore()
{
    cout << "-------------- 第" << this->m_Index << "轮晋级选手信息如下： --------------" << endl;
    vector<int>v;

    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name << " 得分： " <<
             this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;

    system("pause");
    system("cls"); //清屏
    this->show_Menu();
}

//保存记录
void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); //追加的方式写文件

    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        ofs.close();
        return;
    }

    //将每个选手编号和对应的分数 写到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;

    //关闭文件
    ofs.close();

    cout << "记录已经保存" << endl;

    //有记录了，更新标志
    this->fileIsEmpty = false;
}

//控制比赛流程  开始比赛
void SpeechManager::startSpeech()
{
    //第一轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //第二轮比赛
    this->m_Index++;
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //4、保存分数
    this->saveRecord();

    //重置比赛
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();

    cout << "本届比赛完毕！" << endl;
    system("pause");
    system("cls");
}

//读取记录
void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); //读取文件

    if (!ifs.is_open())
    {
        //cout << "文件不存在" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //判断文件存在 并且文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //cout << "文件为空" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件有记录 将记录读取
    this->fileIsEmpty = false;
    ifs.putback(ch);

    string data; //读取一行信息
    int index = 0; //第几届记录
    while (ifs >> data)
    {
        //cout << data << endl;
        vector<string>v;

        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = (int)data.find(",",start); //从0下标开始找,
            if (pos == -1)
            {
                break;
            }
            string temp = data.substr(start, pos - start);
            v.push_back(temp);
            start = pos + 1;
        }
        //将key和value 插入到 m_Record容器中
        this->m_Record.insert(make_pair(index, v));
        index++;
    }

    ifs.close();
}


//展示记录
void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在，或记录为空!" << endl;
    }
    else
    {
        for (int i = 0; i < m_Record.size(); i++)
        {
            cout << "第" << i + 1 << "届 " <<
                 "冠军编号： " << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
                                                                                              "亚军编号： " << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
                                                                                                                                                                           "季军编号： " << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << endl;
        }
    }
    system("pause");
    system("cls");
}

//清空记录
void SpeechManager::clearRecord()
{
    cout << "确认清空?" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        this->initSpeech();

        this->createSpeaker();

        this->loadRecord();

        cout << "清空成功！" << endl;
    }
    system("pause");
    system("cls");
}

//析构函数
SpeechManager::~SpeechManager()
{


}