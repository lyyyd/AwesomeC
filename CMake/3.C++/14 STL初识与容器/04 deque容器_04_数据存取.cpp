#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>

/* 数据存取
at(int idx);		//返回索引idx所指的数据
operator[];		//返回索引idx所指的数据
front();		//返回容器中第一个数据元素
back();		//返回容器中最后一个数据元素
*/

int main()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	for (int i = 0; i < d.size(); i++)
	{
		//cout << d[i] << " ";
		cout << d.at(i) << " ";
	}
	cout << endl;

	try
	{
		cout << d.at(10) << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}

	cout << "第一个元素为： " << d.front() << endl;
	cout << "最后一个元素为： " << d.back() << endl;

	system("pause");
	return 0;
}