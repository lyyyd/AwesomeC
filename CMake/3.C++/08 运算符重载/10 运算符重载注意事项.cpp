#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
1、=   []   ()  和 -> 操作符只能通过成员函数进行重载
2、<< 和 >>只能通过全局函数配合友元函数进行重载
3、不要重载 && 和 || 操作符，因为无法实现短路规则
  4、.   ::    .*    ?:  sizeof   ，  是无法重载的运算符
*/

class MyClass
{
public:
	MyClass(int flag)
	{
		this->flag = flag;
	}
	MyClass& operator+=(MyClass& myclass)
	{
		this->flag += myclass.flag;
		return *this;
	}

	bool operator&&(MyClass& myclass)
	{
		return this->flag && myclass.flag;
	}

	int flag;
};

int main()
{
	MyClass MyClass1(0); //假
	MyClass MyClass2(1); //真

	if (MyClass1 && (MyClass1 += MyClass2))
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}



	system("pause");
	return 0;
}