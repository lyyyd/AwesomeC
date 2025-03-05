#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		this->m_A = 100;
	}
	void func()
	{
		cout << "Base中的func调用" << endl;
	}
	void func(int a)
	{
		cout << "Base中的func(int a)调用" << endl;
	}
	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		this->m_A = 200;
	}
	void func()
	{
		cout << "Son中的func调用" << endl;
	}
	int m_A;
};

//同名成员属性
void test01()
{
	Son s;
	cout << "Son中的m_A: "<< s.m_A << endl;

	cout << "Base中的m_A: " << s.Base::m_A << endl;
}
//同名成员函数
void test02()
{
	Son s;
	s.func();
	s.Base::func();
	//重定义：当子类与父类出现同名成员函数，子类会隐藏父类中所有同名成员函数
	s.Base::func(10);
}

int main()
{

	test01();
	test02();

	system("pause");
	return 0;
}