#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
//swap(vec);  	// 将vec与本身的元素互换

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	cout << "容器互换前： " << endl;
	printVector(v);
	printVector(v2);

	v.swap(v2);

	cout << "容器互换后： " << endl;
	printVector(v);
	printVector(v2);
}

//巧用swap实现收缩内存
void test02()
{
	vector<int>v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "容量： " << v.capacity() << endl;
	cout << "大小： " << v.size() << endl;

	v.resize(3);
	cout << "容量： " << v.capacity() << endl;
	cout << "大小： " << v.size() << endl;

	vector<int>(v).swap(v);
	cout << "容量： " << v.capacity() << endl;
	cout << "大小： " << v.size() << endl;

	printVector(v);
}

int main()
{

	test02();

	system("pause");
	return 0;
}