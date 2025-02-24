#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//注意事项1：如果函数中有一个值有了默认参数，那么从这个值开始，后面都必须有默认参数
int func(int a, int b = 20, int c = 20)
{
	return a + b + c;
}
void test01()
{
	cout << "ret = " << func(10, 30) << endl; //60
}

//注意事项2：函数的声明和实现只能有一个有默认参数，不能同时拥有
void func2(int a = 10, int b = 20);
void func2(int a , int b ) {}

int main()
{
	test01();


	system("pause");
	return 0;
}