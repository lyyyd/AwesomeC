#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const double PI = 3.14;

//设计圆类，求圆周长
//1、设计圆类
class Circle
{
//公共权限
public:

	//获取圆的周长
	double getZC()
	{
		return 2 * PI * m_R;
	}

	//通过行为获取圆的半径
	int getR()
	{
		return m_R;
	}

	//圆的属性  半径
	int m_R;
};

int main()
{
	//通过圆类，创建圆对象
	Circle c1;
	//给圆对象属性赋值
	c1.m_R = 10;
	cout << "圆的周长为：" << c1.getZC() << endl;
	cout << "圆的半径为：" << c1.getR() << endl;

	system("pause");
	return 0;
}