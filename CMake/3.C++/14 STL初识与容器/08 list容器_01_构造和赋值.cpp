#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <list>
#include <vector>
/*
构造
list容器构造函数原型：
list<T> lst;		//list采用模板类实现,对象的默认构造形式
list(beg,end);	//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);		//构造函数将n个elem拷贝给本身。
list(const list &lst);	//拷贝构造函数。

赋值
assign(beg, end);	//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);	//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);	//重载等号操作符
*/

void test01()
{
	list<int> L;
	int arr[] = { 1,2,3,4,5 };
	L.assign(arr, arr + sizeof(arr) / sizeof(int));

	//遍历容器
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

void test02()
{
	list<int> L;
	int arr[] = { 1,2,3,4,5 };
	L.assign(arr, arr + sizeof(arr) / sizeof(int));

	//逆序遍历
	for (list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test03()
{
	//list迭代器是双向迭代器，不是随机访问迭代器
	vector<int>v(10, 100);
	vector<int>::iterator it = v.begin();
	it = it + 1;

	list<int>L(10, 100);
	list<int>::iterator it2 = L.begin();
	it2++;
	it2--;
	//it2 = it2 + 1;  //error 不支持跳跃式访问元素
}

int main()
{
	test02();


	system("pause");
	return 0;
}