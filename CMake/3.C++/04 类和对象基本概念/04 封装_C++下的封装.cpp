#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//人的结构体
struct Person
{
	char Name[64];  //姓名

	//吃饭 人
	void personEat()
	{
		printf("%s在吃饭\n", Name);
	}
};

//狗的结构体
struct Dog
{
	char Name[64];  //姓名

	//吃饭  狗
	void dogEat()
	{
		printf("%s在吃狗粮\n", Name);
	}
};

//C++封装的优点：
//1、将属性和行为作为一个整体，表现生活中的事物
//2、将所有属性和行为，加以权限控制
int main()
{
	Person p;
	strcpy(p.Name, "张三");
	p.personEat();

	Dog d;
	strcpy(d.Name, "旺财");
	d.dogEat();

	//p.dogEat();

	system("pause");
	return 0;
}