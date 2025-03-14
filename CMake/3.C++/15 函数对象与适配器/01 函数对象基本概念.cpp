#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、函数对象，重载()的类，这个类创建的对象称为函数对象，使用时非常像函数调用，因此称为仿函数
class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
		m_Count++;
	}
	int m_Count = 0;
};

void test01()
{
	MyPrint mp;
	mp("hello world");
}
//2、超出普通函数概念，内部可以拥有自己状态
void test02()
{
	MyPrint mp;
	mp("hello world");
	mp("hello world");
	mp("hello world");
	mp("hello world");

	cout << "count = " << mp.m_Count << endl;
}

//3、函数对象可以作为参数 进行传递
void func(MyPrint mp, string text)
{
	mp(text);
}

void test03()
{
	func(MyPrint(), "hello");
}

int main()
{
	test03();


	system("pause");
	return 0;
}