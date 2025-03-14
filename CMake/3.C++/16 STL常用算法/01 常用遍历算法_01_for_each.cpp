#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

void myPrint(int val)
{
	cout << val << endl;
}
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << endl;
	}
};

//1、遍历容器
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for_each(v.begin(), v.end(), myPrint);
	for_each(v.begin(), v.end(), MyPrint());
}

//2、for_each有返回值，返回第三个参数的拷贝
class MyPrint2
{
public:
	void operator()(int val)
	{
		cout << val << endl;
		m_Count++;
	}
	int m_Count = 0;
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	MyPrint2 mp = for_each(v.begin(), v.end(), MyPrint2());
	cout << "count = " << mp.m_Count << endl;
}

//3、for_each算法可以绑定参数
class MyPrint3 : public binary_function<int,int,void>
{
public:
	void operator()(int val , int start) const
	{
		cout << val + start << endl;
	}
};

void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd( MyPrint3() ,1000 ));

}

int main()
{
	test03();


	system("pause");
	return 0;
}