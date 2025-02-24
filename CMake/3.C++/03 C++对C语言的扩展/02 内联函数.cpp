#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、宏缺陷1，运算时要加括号保证完整性
#define MYADD(x,y) ((x) + (y))
void test01()
{
	int a = 10;
	int b = 20;
	int ret = MYADD(10, 20) * 20;
	cout << ret << endl;
}

//2、宏缺陷2，即使加了括号，有些情况依然与预期效果不符
#define MYMIN(a,b)  (((a) < (b)) ? (a) : (b))

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void test02()
{
	int a = 10;
	int b = 20;
	//int ret = MYMIN(++a, b);  //12  与预期效果不符
	int ret = mymin(++a, b);    //11  预期效果
	cout << ret << endl;
}

//内联函数
//本质是一个普通函数，会在适当的时候做展开，带来了以空间换时间的优点，解决宏的缺陷
//函数声明和实现同时加inline才会按照内联方式处理
inline void func();
inline void func() {};

int main()
{
	test02();


	system("pause");
	return 0;
}