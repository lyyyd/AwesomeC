#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//重载
void func()
{

}

void func(int a)
{

}

//重定义
class Base
{
public:
	void func()
	{

	}
	void func(int a)
	{

	}
};

class Son :public Base
{
public:
	void func()
	{

	}
};

void test01()
{
	Son s;
	s.Base::func(10);
}

//重写
class Base2
{
public:
	virtual void func()
	{
	}
};

class Son2 :public Base2
{
public:
	void func()
	{
	}
};

void test02()
{
	Base2* b = new Son2;
	b->func();
}

int main()
{



	system("pause");
	return 0;
}