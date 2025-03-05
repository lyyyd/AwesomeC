#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////Java页面
//class Java
//{
//public:
//	//公共头
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//
//	//公共底
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//
//	//公共学科列表
//	void list()
//	{
//		cout << "公共的学科分类列表" << endl;
//	}
//
//	//显示具体教程
//	void content()
//	{
//		cout << "Java教程" << endl;
//	}
//};
//
////Python学科
//class Python
//{
//public:
//	//公共头
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//
//	//公共底
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//
//	//公共学科列表
//	void list()
//	{
//		cout << "公共的学科分类列表" << endl;
//	}
//
//	//显示具体教程
//	void content()
//	{
//		cout << "Python教程" << endl;
//	}
//};
//
////CPP学科
//class CPP
//{
//public:
//	//公共头
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//
//	//公共底
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//
//	//公共学科列表
//	void list()
//	{
//		cout << "公共的学科分类列表" << endl;
//	}
//
//	//显示具体教程
//	void content()
//	{
//		cout << "CPP教程" << endl;
//	}
//};

//基类  父类
class BasePage
{
public:
	void header()
	{
		cout << "公共的头部" << endl;
	}

	//公共底
	void footer()
	{
		cout << "公共的底部" << endl;
	}

	//公共学科列表
	void list()
	{
		cout << "公共的学科分类列表" << endl;
	}
};

//继承 语法： class 子类/派生类 ： 继承方式  父类/基类
class Java : public BasePage
{
public:
	void content()
	{
		cout << "Java教程" << endl;
	}
};

class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python教程" << endl;
	}
};

class CPP :public BasePage
{
public:
	void content()
	{
		cout << "CPP教程" << endl;
	}
};

int main()
{
	cout << "Java页面内容如下：" << endl;
	Java java;
	java.header();
	java.footer();
	java.list();
	java.content();
	cout << "--------------" << endl;

	cout << "Python页面内容如下：" << endl;
	Python py;
	py.header();
	py.footer();
	py.list();
	py.content();
	cout << "--------------" << endl;

	cout << "CPP页面内容如下：" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.list();
	cpp.content();


	system("pause");
	return 0;
}