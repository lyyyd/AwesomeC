#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

/*  构造
vector<T> v;			     //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());	 //将 v[begin(), end()) 区间中的元素拷贝给本身。
vector(n, elem);		     //构造函数将n个elem拷贝给本身。
vector(const vector &vec);   //拷贝构造函数。
*/
//打印vector容器
void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v;

	int arr[] = { 1,2,3,4,5 };

	vector<int>v2(arr, arr + sizeof(arr) / sizeof(int));
	printVector(v2);

	vector<int>v3(v2.begin(), v2.end());
	printVector(v3);

	vector<int>v4(v3);
	printVector(v4);

	vector<int>v5(10, 100);
	printVector(v5);
}

/*  赋值
vector& operator=(const vector &vec);  //重载等号操作符
assign(beg, end);       			   //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);        			   //将n个elem拷贝赋值给本身。
*/
void test02()
{
	int arr[] = { 1,2,3,4,5 };

	vector<int>v(arr, arr + sizeof(arr) / sizeof(int));
	printVector(v);

	vector<int>v2;
	v2 = v;
	printVector(v2);

	vector<int>v3;
	v3.assign(v2.begin(), v2.end());
	printVector(v3);

	vector<int>v4;
	v4.assign(5, 1000);
	printVector(v4);
}

//提高：vector动态扩展机制，并不是以2倍的容量进行扩展，大约1.5倍左右
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
}

int main()
{
	test03();


	system("pause");
	return 0;
}