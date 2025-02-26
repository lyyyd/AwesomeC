#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//#pragma pack(1)

class Person
{
public:
	//非静态成员变量 属于类对象上
	int m_A;

	double m_C;

	static int m_B;  //静态成员变量 不属于类对象上

	void func(){}   //非静态成员函数 不属于类对象上

	static void func2() {}  //静态成员函数 不属于类对象上
};
int Person::m_B = 100;

void test01()
{
	//空类 大小 是1字节
	cout << sizeof(Person) << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}