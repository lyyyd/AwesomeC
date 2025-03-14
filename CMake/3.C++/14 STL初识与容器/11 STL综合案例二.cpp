#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <ctime>

/* 员工分组
公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工Worker信息有: 姓名  工资组成；部门分为：策划（0号）、美术（1号）、研发（2号）
利用createrWorker创建员工
利用setGroup函数随机给10名员工分配部门和工资（工资范围10000~19999）
通过multimap进行信息的插入  key(部门编号) value(员工)
最终分部门显示员工信息
*/

enum {CEHUA,MEISHU,YANFA};

//员工类
class Worker
{
public:
    string m_Name; //姓名
    int m_Money; //工资
};

void createWorker(vector<Worker>& v)
{
    string nameseed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameseed[i];

        worker.m_Money = rand() % 10000 + 10000;  // 10000 ~ 19999

        v.push_back(worker);
    }
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
    //取出每个员工，分派到不同部门中
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //随机部门编号 0 1 2
        int dId = rand() % 3;

        //将部门编号 和 具体员工 插入到map容器中
        m.insert(make_pair(dId, *it));
    }
}

void showGroup(multimap<int, Worker>& m)
{
    //0 A  0 B  0  D   1  C  1  E  2  I
    cout << "策划部门人员信息如下： " << endl;

    multimap<int,Worker>::iterator pos  = m.find(CEHUA);

    //统计部门人员
    int num = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < num; pos++ , index++)
    {
        cout << "部门编号： " << pos->first << " 姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
    }

    cout << "美术部门人员信息如下： " << endl;
    pos = m.find(MEISHU);
    num = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < num; pos++, index++)
    {
        cout << "部门编号： " << pos->first << " 姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
    }

    cout << "研发部门人员信息如下： " << endl;
    pos = m.find(YANFA);
    num = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < num; pos++, index++)
    {
        cout << "部门编号： " << pos->first << " 姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
    }

}

int main()
{
    srand((unsigned int)time(NULL));

    //1、创建10个员工
    vector<Worker>v;
    createWorker(v);

    //2、给员工分组
    multimap<int, Worker> m;
    setGroup(v, m);

    //3、分部门显示员工
    showGroup(m);

    //测试
    //for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    //{
    //	cout << "姓名： " << it->m_Name << " 工资： " << it->m_Money << endl;
    //}

    system("pause");
    return 0;
}