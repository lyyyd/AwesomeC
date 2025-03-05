#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// --------------------- 公共继承 --------------------
class Base1
{
public:
	int m_A;
protected :
	int m_B;
private:
	int m_C;
};

class Son1 : public Base1
{
public:
	void func()
	{
		m_A = 100; //父类中的公共权限，在子类中变为 公共权限
		m_B = 100; //父类中的保护权限，在子类中变为 保护权限
		//m_C = 100; //父类中私有权限，子类访问不到
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 200; //在Son1中m_A是公共权限，类外可以访问
	//s1.m_B = 200; //在Son1中m_B是保护权限，类外不可以访问
}


// --------------------- 保护继承 --------------------
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100; //父类中的公共权限，在子类中变为 保护权限
		m_B = 100; //父类中的保护权限，在子类中变为 保护权限
		//m_C = 100; //父类中私有权限，子类访问不到
	}
};

void test02()
{
	Son2 s2;
	//s2.m_A = 100;  //在Son2中m_A变为保护权限，类外访问不到
	//s2.m_B = 100;  //在Son2中m_B变为保护权限，类外访问不到
	//s2.m_C = 100;  //在Son2中都访问不到，类外更访问不到
}

// --------------------- 私有继承 --------------------
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 100; //父类中的公共权限，在子类中变为 私有权限
		m_B = 100; //父类中的保护权限，在子类中变为 私有权限
		//m_C = 100; //父类中私有权限，子类访问不到
	}
};

class GrandSon :public Son3
{
public:
	void func()
	{
		//m_A = 100; //在Son3中m_A变为私有权限，因为访问不到
		//m_B = 100; //在Son3中m_B变为私有权限，因为访问不到
	}
};

void test03()
{
	Son3 s3;
	//s3.m_A = 100; //在Son3中m_A变为私有权限，类外访问不到
	//s3.m_B = 100; //在Son3中m_B变为私有权限，类外访问不到
	//s3.m_C = 100; //在Son3中都访问不到，类外更访问不到
}

int main()
{



	system("pause");
	return 0;
}