#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);

	int num =  count(v.begin(), v.end(), 30);
	cout << "30的个数为： " << num << endl;
}

//如果存储的是自定义数据类型，需要重载==
class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
	}
	bool operator==(const Person & p)
	{
		return this->m_Age == p.m_Age;
	}
	int m_Age;
};
void test02()
{
	vector<Person>v;
	v.push_back(Person(10));
	v.push_back(Person(20));
	v.push_back(Person(30));
	v.push_back(Person(20));
	v.push_back(Person(25));

	Person p(20);
	int num =  count(v.begin(), v.end(), p);
	cout << "20岁年龄的人员个数为： " << num << endl;
}

int main()
{
	test02();


	system("pause");
	return 0;
}