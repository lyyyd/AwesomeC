#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << "查找到元素： " << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重载==
	bool operator==(const Person & p)
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}
	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	Person p("aaa", 10);

	vector<Person>::iterator pos =  find(v.begin(), v.end(), p);
	if (pos != v.end())
	{
		cout << "找到了元素，姓名： " << (*pos).m_Name << " 年龄： " << pos->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main()
{

	test02();

	system("pause");
	return 0;
}