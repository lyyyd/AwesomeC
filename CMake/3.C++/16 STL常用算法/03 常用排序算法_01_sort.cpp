#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	sort(v.begin(), v.end()); //默认升序排序规则
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	sort(v.begin(), v.end(), greater<int>()); //利用内建函数对象 ，改为降序
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}
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

class myCompare
{
public:
	bool operator()(Person p1, Person p2)
	{
		return p1.m_Age > p2.m_Age;
	}
};

void test02()
{
	vector<Person>v;
	v.push_back(Person("aaa", 18));
	v.push_back(Person("bbb", 19));
	v.push_back(Person("ccc", 20));
	v.push_back(Person("ddd", 21));
	v.push_back(Person("eee", 22));

	sort(v.begin(), v.end(), myCompare());

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << endl;
	}
}

int main()
{
	test02();


	system("pause");
	return 0;
}
