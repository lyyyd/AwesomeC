#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、C++会默认给每个类添加至少3个函数
//默认构造 空实现
//析构函数 空实现
//拷贝构造 值拷贝

//2、创建规则
//规则1：如果我们提供了有参构造，编译器不提供默认构造 但依然提供拷贝构造
//规则2：如果我们提供了拷贝构造，编译器就不提供普通构造

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "Person的拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age;
};

void test01()
{
	Person p1(100);

	Person p2(p1);

	cout << "p2的年龄： " << p2.m_Age << endl;

}

void test02()
{
	Person p;

}

int main()
{
	test01();


	system("pause");
	return 0;
}