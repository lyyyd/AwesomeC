#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>

/* 高级排序
创建Person数据类型，Person中成员属性有姓名、年龄，并创建出至少5个对象，存放在list容器中
将Person自定义数据类型进行排序
排序规则：按照年龄进行升序排列
输出排序前和排序后的人员信息
*/

class Person
{
public:
	Person(string name, int age , int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	//重载==
	bool operator==(const Person& p) const
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
		{
			return true;
		}
		return false;
	}

	string m_Name; //姓名
	int m_Age;  //年龄
	int m_Height; //身高
};

bool myCompare(Person& p1, Person& p2)
{
	//按照年龄进行升序，如果年龄相同按照身高进行降序
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}

void printList(list<Person>& L)
{
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height <<  endl;
	}
}

void test01()
{
	list<Person>L;
	Person p1("刘备", 20 , 170);
	Person p2("关羽", 25 , 180);
	Person p3("张飞", 22 , 175);
	Person p4("赵云", 23, 177);
	Person p5("吕布", 24, 168);
	Person p6("曹操", 22, 173);
	Person p7("孙权", 22, 190);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);

	cout << "排序前遍历容器的结果为： " << endl;
	printList(L);

	cout << "-------------------" << endl;

	L.sort(myCompare);

	cout << "排序后遍历容器的结果为： " << endl;
	printList(L);

	//删除刘备
	L.remove(p1);
	cout << "删除刘备后遍历容器的结果为： " << endl;
	printList(L);
}

int main()
{
	test01();


	system("pause");
	return 0;
}