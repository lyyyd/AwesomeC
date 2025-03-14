#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

void test01()
{
	vector< vector<int> >v;

	//创建3个小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	//给每个小容器插入5个数据
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
	}

	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历大容器
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it -> vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main()
{
	test01();


	system("pause");
	return 0;
}