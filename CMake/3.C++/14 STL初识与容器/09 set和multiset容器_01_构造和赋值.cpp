#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>

/*
构造
set<T> st;		//默认构造函数：
set(const set &st);	//拷贝构造函数
赋值
set& operator=(const set &st);	//重载等号操作符
*/

void test01()
{
	//插入的数据 自动被排序
	set<int>s;
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(40);
	s.insert(20);
	s.insert(20);  //重复的数据  插入失败  可以利用 multiset 插入重复的元素

	set<int>s2(s);

	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	multiset<int>ms;
	ms.insert(100);
	ms.insert(300);
	ms.insert(400);
	ms.insert(200);
	ms.insert(500);
	ms.insert(300);

	multiset<int>ms2;
	ms2 = ms;

	for (multiset<int>::iterator it = ms2.begin(); it != ms2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}