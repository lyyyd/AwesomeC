#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base1
{
public:
	Base1()
	{
		this->m_A = 100;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		this->m_A = 200;
	}
	int m_A;
};

class Son : public Base1, public Base2
{
public:
	int m_C;
	int m_D;
};

int main()
{
	cout << "sizeof son = " << sizeof(Son) << endl;

	Son son;
	//如果父类中有同名成员出现，需要加作用域区分
	cout << son.Base1::m_A << endl;
	cout << son.Base2::m_A << endl;

	system("pause");
	return 0;
}