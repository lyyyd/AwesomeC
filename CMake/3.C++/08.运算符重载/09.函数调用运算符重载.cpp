#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、实现输出
class myPrint
{
public:
	//重载()
	void operator()(string text)
	{
		cout << text << endl;
	}
};

void MyPrint(string text)
{
	cout << text << endl;
}

void test01()
{
	myPrint mp;
	mp("hello world");  //非常像函数调用，因此称为仿函数，对象也称为函数对象
	MyPrint("hello world");
}

//2、实现两个数字相加并返回结果
class myAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};

void test02()
{
	myAdd add;
	cout << add(10, 10) << endl;
	//提高
	cout << myAdd()(100, 100) << endl;  //匿名函数对象 特点：当前行执行过后，立即释放
}

int main()
{
	test02();


	system("pause");
	return 0;
}