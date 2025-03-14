#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test01()
{
	vector <Person>v;

	//创建5个对象
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//将数据插入到容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}
}

void test02()
{
	vector <Person *>v;
	//创建5个对象
	Person p1("aaa", 100);
	Person p2("bbb", 200);
	Person p3("ccc", 300);
	Person p4("ddd", 400);
	Person p5("eee", 500);

	//将数据插入到容器中
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍历容器
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it -> Person*
		cout << "姓名： " << (*it)->m_Name << "年龄： " << (*it)->m_Age << endl;
	}
}

int main()
{

	test02();

	system("pause");
	return 0;
}