#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base的默认构造调用" << endl;
	}
	~Base()
	{
		cout << "Base的析构函数调用" << endl;
	}
};

class Other
{
public:
	Other()
	{
		cout << "Other的默认构造调用" << endl;
	}
	~Other()
	{
		cout << "Other的析构函数调用" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		cout << "Son的默认构造调用" << endl;
	}
	~Son()
	{
		cout << "Son的析构函数调用" << endl;
	}
	Other other;
};

void test01()
{
	//Base base;

	Son son;
}


class Base2
{
public:
	Base2(int a)
	{
		cout << "Base2的默认构造调用" << endl;
		this->m_A = a;
	}
	~Base2()
	{
		cout << "Base2的析构函数调用" << endl;
	}
	int m_A;
};

class Son2 :public Base2
{
public:
	Son2(int a) : Base2(a)
	{
		cout << "Son2的默认构造调用" << endl;
	}
	~Son2()
	{
		cout << "Son2的析构函数调用" << endl;
	}
};

void test02()
{
	Son2 s2(200);
	cout << s2.m_A << endl;
}

int main()
{
	test01();
	test02();


	system("pause");
	return 0;
}