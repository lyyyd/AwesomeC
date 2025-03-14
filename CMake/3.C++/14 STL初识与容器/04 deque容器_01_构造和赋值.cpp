#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>

/*  构造
deque<T> deqT;		//默认构造形式
deque(beg, end);		//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);		//构造函数将n个elem拷贝给本身。
deque(const deque &deq);	//拷贝构造函数
*/

void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 1000;
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	printDeque(d);

	deque<int>d2(d.begin(), d.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}

/*  赋值
deque& operator=(const deque &deq);		//重载等号操作符
assign(beg, end);				//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); 				//将n个elem拷贝赋值给本身
*/
void test02()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	deque<int>d2;
	d2 = d;
	printDeque(d2);

	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 200);
	printDeque(d4);

}

int main()
{
	test02();


	system("pause");
	return 0;
}