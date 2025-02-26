#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myArray.h"

void test01()
{
	//MyArray arr;
	MyArray arr(10);

	cout << "数组容量为： " << arr.getCapacity() << endl;
	cout << "数组大小为： " << arr.getSize() << endl;

	arr.pushBack(100);
	arr.pushBack(200);
	arr.pushBack(300);
	arr.pushBack(400);

	cout << "数组容量为： " << arr.getCapacity() << endl;
	cout << "数组大小为： " << arr.getSize() << endl;

	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;

	arr.setData(0, 1000);

	//拷贝构造
	MyArray arr2(arr);
	cout << "拷贝的数组遍历结果为： " << endl;
	for (int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << " ";
	}
	cout << endl;
}

//遗留问题 √
void test02()
{
	MyArray arr(10);
	arr.pushBack(10);
	arr.pushBack(20);
	arr.pushBack(30);

	cout << "第一个数据为：" << arr.getData(0) << endl;
	cout << "第一个数据为：" << arr[0] << endl;

	arr.setData(0, 1000);
	arr[0] = 2000;
	cout << "第一个数据为：" << arr.getData(0) << endl;

	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{

	test02();

	system("pause");
	return 0;
}