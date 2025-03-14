#include "fileManager.h"

//加载CSV格式文件
void FileManager::loadCSVData(string path, map<string, map<string, string>>& mData)
{
    //读文件
    ifstream ifs(path);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //第一个数据
    string firstLine;
    ifs >> firstLine;


    //cout << "第一行数据为： " << firstLine << endl;
    //heroId,heroName,heroHp,heroAtk,heroDef,heroInfo

    vector<string>vFirst; //第一行解析后数据放入的容器

    this->parseLineToVector(firstLine, vFirst);

    //测试
    /*for (vector<string>::iterator it = vFirst.begin(); it != vFirst.end(); it++)
    {
        cout << *it << endl;
    }*/

    string otherLine;
    while (ifs >> otherLine)
    {
        //cout << "otherLine = " << otherLine << endl;

        vector<string>vOther;

        this->parseLineToVector(otherLine, vOther);

        map<string, string>m;
        for (int i = 0; i < vFirst.size(); i++)
        {
            m.insert(make_pair(vFirst[i], vOther[i]));
        }
        //将小map容器插入到大map容器中
        mData.insert(make_pair(vOther[0], m));
    }

    //cout << "第一个英雄姓名： " << mData["1"]["heroName"] << endl;
    //cout << "第二个英雄血量： " << mData["2"]["heroHp"] << endl;
    //cout << "第三个英雄攻击力： " << mData["3"]["heroAtk"] << endl;
}

//解析单行数据到vector容器中
void FileManager::parseLineToVector(string line, vector<string>& v)
{
    int pos = -1;
    int start = 0;

    while (true)
    {
        pos = (int)line.find(",", start);
        if (pos == -1)
        {
            //最后一个单词处理
            string temp = line.substr(start);
            v.push_back(temp);
            break;
        }
        string temp = line.substr(start, pos - start);
        v.push_back(temp);
        start = pos + 1;
    }

}