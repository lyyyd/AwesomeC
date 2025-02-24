#include <iostream>
using namespace std;

//双冒号作用域运算符

int atk = 1000;

void test01()
{
	int atk = 2000;

	cout << atk << endl; //就近原则
	cout << ::atk << endl; //::前如果没有任何内容，代表引用全局作用域

	//双冒号前可以有类名或者命名空间名
	std::cout << "hello world" << std::endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}
