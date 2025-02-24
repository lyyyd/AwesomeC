#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//数组的引用
void test01()
{
	int arr[5] = { 1,2,3,4,5 };

	//1、先定义数组的类型，在通过类型定义数组的引用
	typedef int(ARRAY_TYPE)[5];
	ARRAY_TYPE& arr_ref1 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << arr_ref1[i] << " ";
	}
	cout << endl;

	//2、先定义数组引用的类型，在定义数组的引用
	typedef int(&ARRAY_TYPE_REF)[5];
	ARRAY_TYPE_REF arr_ref2 = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << arr_ref2[i] << " ";
	}
	cout << endl;

	//3、直接定义数组引用
	int(&arr_ref3)[5] = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << arr_ref3[i] << " ";
	}
	cout << endl;
}

int main()
{
	test01();


	system("pause");
	return 0;
}