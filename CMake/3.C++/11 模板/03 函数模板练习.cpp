#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//利用函数模板实现交换
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//利用选择排序实现降序序列
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (i != max)
		{
			mySwap(arr[i], arr[max]);
		}
	}

}

template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试char数组
void test01()
{
	char charArray[] = "abcdefg";
	int len = strlen(charArray);
	cout << "排序前数组遍历结果为：" << endl;
	printArray(charArray, len);
	mySort(charArray, len);
	cout << "排序后数组遍历结果为：" << endl;
	printArray(charArray, len);
}

//测试int数组
void test02()
{
	int intArray[] = { 10,30,50,20,40 };
	int len = sizeof(intArray) / sizeof(int);
	cout << "排序前数组遍历结果为：" << endl;
	printArray(intArray, len);
	mySort(intArray, len);
	cout << "排序后数组遍历结果为：" << endl;
	printArray(intArray, len);
}

int main()
{
	test02();


	system("pause");
	return 0;
}