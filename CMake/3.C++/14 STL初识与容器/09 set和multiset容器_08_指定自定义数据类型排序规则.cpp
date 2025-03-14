#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>

/*
需求说明：
创建Person类，属性为姓名和年龄
创建set容器，指定排序规则为按照年龄降序插入到容器中
测试：
创建5个Person类型的对象，插入到set容器
遍历容器，满足排序规则
*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name; //姓名
	int m_Age;  //年龄
};

class myComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		//按年龄 降序
		return p1.m_Age > p2.m_Age;
	}
};

int main()
{
	set<Person, myComparePerson>s;
	Person p1("aaa", 10);
	Person p2("bbb", 30);
	Person p3("ccc", 50);
	Person p4("ddd", 20);
	Person p5("eee", 40);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Person, myComparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄：" << it->m_Age << endl;
	}

	system("pause");
	return 0;
}