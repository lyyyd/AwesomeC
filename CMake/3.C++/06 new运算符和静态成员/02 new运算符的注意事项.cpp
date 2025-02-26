#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*  malloc 和 new 区别
1、malloc是C创建堆区数据的库函数，new是C++创建堆区数据的运算符
2、malloc对应释放的库函数是free，new对应释放的运算符是delete ，不可以混用
3、malloc返回值是void*， new返回创建对象的指针类型
4、malloc不会调用构造，free不会调用析构，new自动调用构造函数，delete自动调用析构函数
5、malloc需要显式地指出所需内存的大小，new申请内存分配时无需指定内存块的大小，编译器会根据类型自行计算。
*/

//不要用万能指针 接受new出来的对象
class Person
{
public:
	Person()
	{
		cout << "Person 的构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}
};
void test01()
{
	void* p = new Person;
	delete p;
}
int main()
{

	test01();

	system("pause");
	return 0;
}