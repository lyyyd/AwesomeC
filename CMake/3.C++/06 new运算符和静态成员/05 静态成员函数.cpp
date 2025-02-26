#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	//静态成员函数  只有一份
	static void func()
	{
		//m_A = 100;  //静态成员函数 不能访问非静态成员变量
		m_B = 200;  //静态成员函数 可以访问静态成员变量
		cout << "静态成员函数func调用" << endl;
	}

	//非静态成员函数
	void fun2()
	{
		m_A = 100;  //非静态成员函数 可以访问非静态成员变量
		m_B = 200;  //非静态成员函数 可以访问静态成员变量
		cout << "非静态成员函数fun2调用" << endl;
	}

	int m_A;
	static int m_B;

private:
	static void fun3()
	{

	}
};
int Person::m_B = 100;

void test01()
{
	//访问方式
	//1、通过对象
	Person p1;
	p1.func();
	p1.fun2();

	//2、通过类名
	Person::func();
	//Person::fun2(); //通过类名的方式只能调用静态成员函数

	//静态成员函数也是有访问权限的
	//Person::fun3();
}

int main()
{
	test01();


	system("pause");
	return 0;
}