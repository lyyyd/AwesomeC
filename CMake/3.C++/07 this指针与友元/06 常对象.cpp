#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	void func1() const
	{
		cout << "常函数调用" << endl;
		m_Height = 190;
	}

	void func2()
	{
		cout << "普通成员函数调用" << endl;
	}

	int m_Age;
	mutable int m_Height; //特殊成员属性，前面加关键字 mutable后 就可以在常函数和常对象中修改
};

int main()
{
	const Person p1; //常对象
	//p1.m_Age = 100;
	p1.func1();
	//p1.func2(); //常对象只能调用常函数 不能调用普通成员函数
	p1.m_Height = 180;

	system("pause");
	return 0;
}