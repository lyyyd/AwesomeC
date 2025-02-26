#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//静态成员变量
class Person
{
public:
	//静态成员变量 只有一份，被所有对象共享
	//在编译阶段分配内存，在对象创建之前就分配好了内存
	static int m_A;  //类内声明

private:

	static int m_B;
};
int Person::m_A = 100; //类外初始化
int Person::m_B = 200; //类外初始化


void test01()
{
	cout << Person::m_A << endl;

	//访问静态成员变量
	//1、通过对象
	Person p1;
	cout << p1.m_A << endl;

	//2、通过类名
	cout << Person::m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p1.m_A << endl;
	cout << Person::m_A << endl;

	//静态成员变量也是有访问权限的
	//cout << p1.m_B << endl;  //类外访问不到私有静态成员变量
}

int main()
{
	test01();


	system("pause");
	return 0;
}