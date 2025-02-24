#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//int& ref = 10; //错误，引用必须引可修改的内存
	const int& ref = 10; //编译器优化了代码 int temp = 10; const int & ref = temp;

	//如果数据还是在局部的作用域下，依然可以修改
	//ref = 20;
	int* p = (int *) & ref;
	*p = 20;
	cout << ref << endl;
}

//const使用场景，可以修饰函数中的形参，防止误操作
//传引用可以不用创建副本，但是可能会修改到实参
void showNum(const int &num)
{
	//num = 20;
	cout << num << endl;
}
void test02()
{
	int num = 10;
	showNum(num);
}

int main()
{
	test02();


	system("pause");
	return 0;
}