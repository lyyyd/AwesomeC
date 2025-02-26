#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//构造函数分类
//1、按参数分类  无参构造（默认构造） 和 有参构造
//2、按类型分类  普通构造  拷贝构造

class Person
{
public:
	//无参构造
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	//有参构造
	Person(int a)
	{
		cout << "Person的有参构造函数调用" << endl;
	}
	//拷贝构造  复制  克隆
	Person(const Person & p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
	}
};

int main()
{
	Person p;
	Person p2(10);
	Person p3(p);

	system("pause");
	return 0;
}