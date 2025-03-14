#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

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

class myCompare :public binary_function<Person * ,Person * ,bool>
{
public:
	bool operator()(Person * p1 , Person * p2) const
	{
		if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	vector<Person* >v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	Person* p = new Person("ccc", 30);

	vector<Person *>::iterator pos  = find_if(v.begin(), v.end(), bind2nd( myCompare() , p));
	if (pos != v.end())
	{
		cout << "找到了元素，姓名： " << (*pos)->m_Name << " 年龄： " << (*pos)->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	system("pause");
	return 0;
}