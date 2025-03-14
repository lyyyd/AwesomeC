#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stack>

/*  stack容器常用接口
构造函数：
stack<T> stk;			//stack采用模板类实现， stack对象的默认构造形式
stack(const stack &stk);	//拷贝构造函数
赋值操作：
stack& operator=(const stack &stk);	//重载等号操作符
数据存取：
push(elem);		//向栈顶添加元素
pop();		//从栈顶移除元素
top();		//返回栈顶元素
大小操作：
empty();		//判断栈是否为空
size();		//返回栈的大小
*/

int main()
{
	stack<int>s;
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	stack<int>s2;
	s2 = s;

	cout << "元素个数为： " << s2.size() << endl;

	//只要栈不为空，查看栈顶，并执行出栈
	while (!s2.empty())
	{
		cout << "栈顶元素： " << s2.top() << endl;
		//出栈
		s2.pop();
	}

	cout << "元素个数为： " << s2.size() << endl;

	system("pause");
	return 0;
}