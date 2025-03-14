#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>
/*
交换
swap(st);		//交换两个映射容器

大小
empty();		//判断容器是否为空
size();		    //返回容器中元素的个数
*/

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
}

int main()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 200));
	m2.insert(pair<int, int>(30, 300));

	cout << "交换前，遍历容器结果为： " << endl;
	printMap(m);
	printMap(m2);
	cout << "-------------------------" << endl;
	m.swap(m2);
	cout << "交换后，遍历容器结果为： " << endl;
	printMap(m);
	printMap(m2);

	if (m.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空，大小： " << m.size() << endl;
	}

	system("pause");
	return 0;
}