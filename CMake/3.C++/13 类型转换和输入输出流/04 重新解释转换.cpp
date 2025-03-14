#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//重新解释转换  不安全 ，不建议使用
void test01()
{
	int a = 10;
	int* p = reinterpret_cast<int*>(a);
}

class Base{};
class Other{};
void test02()
{
	Base* b = NULL;
	Other* o = reinterpret_cast<Other*>(b);
}

int main()
{



	system("pause");
	return 0;
}