#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

/*  评委打分案例需求
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
其中选手为Player类，属性为姓名和最终获得的平均分
5名选手存放在vector容器中，调用createPlayer函数完成选手的初始化操作
调用setScore函数进行打分操作，评委打分要求随机60~100之间
最终调用showScore函数显示每个选手最终得分情况
*/

//选手类
class Player
{
public:
	Player(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;  //姓名
	int m_Score;    //平均分
};

void createPlayer(vector<Player>& v)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Player p(name, score);
		v.push_back(p);
	}
}

//打分
void setScore(vector<Player>& v)
{
	//取出容器中的每个选手，进行评委打分
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将分数 存放在deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;   //60 ~ 100   0 ~ 40
			d.push_back(score);
		}

		//排序
		sort(d.begin(), d.end());

		//去除最高分和最低分
		d.pop_front();
		d.pop_back();

		//测试  每个评委给选手的打分情况
		//cout << "选手： " << it->m_Name << "的分数为： " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//获取总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		//计算平均分
		int avg = sum / d.size();

		//将分数 赋值到选手上
		it->m_Score = avg;

	}

}


//显示最终分数
void showScore(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 平均分： " << it->m_Score << endl;
	}
}

int main()
{
	//添加随机数种子
	srand((unsigned int)time(NULL));

	//1、准备容器，存放每个选手
	vector<Player>v;

	//2、创建选手，放入到容器中
	createPlayer(v);

	//3、评委打分
	setScore(v);

	//4、显示最终分数
	showScore(v);

	//测试
	//for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 平均分： " << it->m_Score << endl;
	//}

	system("pause");
	return 0;
}