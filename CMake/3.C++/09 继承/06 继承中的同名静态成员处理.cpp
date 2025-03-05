#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	static int m_A;
	static void fun()
	{
		cout << "Base下的func调用" << endl;
	}
	static void fun(int a)
	{
		cout << "Base下的func(int a)调用" << endl;
	}
};
int Base::m_A = 100;

class Son:public Base
{
public:
	static int m_A;
	static void fun()
	{
		cout << "Son下的func调用" << endl;
	}
};
int Son::m_A = 200;

//同名成员属性
void test01()
{
	//1、通过对象调用
	Son s;
	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;

	//2、通过类名调用
	cout << "Son下的m_A = " << Son::m_A << endl;
	cout << "Base下的m_A = " << Son::Base::m_A << endl;
}

//同名成员函数
void test02()
{
	//1、通过对象调用
	Son s;
	s.fun();
	s.Base::fun();

	//2、通过类名调用
	Son::fun();
	Son::Base::fun();

	Son::Base::fun(10);
}

int main()
{
	test01();
	test02();


	system("pause");
	return 0;
}