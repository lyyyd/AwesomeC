#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}
	Person(const Person &p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
	int m_Age;
};

//1、已经创建好的对象 初始化新对象
void test01()
{
	Person p1(18);
	cout << "p1的年龄为： " << p1.m_Age <<  endl;

	Person p2(p1);
	cout << "p2的年龄为： " << p2.m_Age << endl;
}

//2、值传递的方式 给函数参数传值
void func(Person p)
{
	cout << "p的年龄为： " << p.m_Age << endl;
}
void test02()
{
	Person p(20);
	func(p);
}

//3、以值方式 返回局部对象
Person func2()
{
	Person p(30);
	return p;
}
void test03()
{
	Person p = func2();
	cout << "p的年龄为： " << p.m_Age << endl;
}

int main()
{

	test03();

	system("pause");
	return 0;
}