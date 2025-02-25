#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//访问权限 三种
//public ：   公共权限  成员 类内可以访问  类外也可以访问
//protected： 保护权限  成员 类内可以访问  类外不可以访问
//private ：  私有权限  成员 类内可以访问  类外不可以访问
//class 和 struct 的区别
//class 默认访问权限是私有的
//struct 默认访问权限是公共的
class Person
{
public:
	string m_Name; //姓名
protected:
	string m_Car;  //汽车
private:
	int m_Pwd;     //银行卡密码
public:
	void func()
	{
		m_Name = "张三";  //public 类内可以访问
		m_Car = "奔驰";   //protected 类内可以访问
		m_Pwd = 12345;    //private  类内可以访问
	}
};

int main()
{
	Person p1;
	p1.m_Name = "李四";   //public 类外可以访问
	//p1.m_Car = "劳斯莱斯"; //protected 类外不可以访问
	//p1.m_Pwd = 123;       //private 类外不可以访问
	p1.func();

	system("pause");
	return 0;
}