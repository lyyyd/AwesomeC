#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		m_Age = 18;
		m_Height = 180;
	}

	//this 本质是指针常量  Person * const this;

	//通过常函数 修饰成 const Person * const this;
	void showAge() const
	{
		//this = NULL; //指针的指向是不可以修改的
		//m_Age = 100;  //常函数中 指针指向的值也不可以改了
		cout << "m_Age = " << this->m_Age << endl;
		m_Height = 190;
		cout << "m_Height = " << this->m_Height << endl;
	}

	//注意事项 成员函数不能即用 static修饰 又用 const修饰
	//static void func() const {}

	int m_Age;
	mutable int m_Height;
};

int main()
{
	Person p;
	p.showAge();


	system("pause");
	return 0;
}