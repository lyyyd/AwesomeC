#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class myGreater
{
public:
	bool operator()(int v)
	{
		return v > 20;
	}
};

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	//int num =  count_if(v.begin(), v.end(), myGreater());
	int num = count_if(v.begin(), v.end(), bind2nd( greater<int>() , 20  ));
	cout << "大于20的元素个数为： " << num << endl;
}

class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
	}
	int m_Age;
};

class myCompare :public binary_function<Person ,Person ,bool>
{
public:
	bool operator()(Person p1,Person p2) const
	{
		return p1.m_Age > p2.m_Age;

	}
};

void test02()
{
	vector<Person >v;
	v.push_back(Person(10));
	v.push_back(Person(20));
	v.push_back(Person(30));
	v.push_back(Person(40));
	v.push_back(Person(50));
	v.push_back(Person(60));
	v.push_back(Person(70));

	Person p(30);
	//统计容器中比p人员年龄大的个数有多少
	int num =  count_if(v.begin(), v.end(), bind2nd(myCompare(), p));
	cout << "容器中大于p人员的年龄的个数为： " << num << endl;
}

int main()
{
	test02();


	system("pause");
	return 0;
}