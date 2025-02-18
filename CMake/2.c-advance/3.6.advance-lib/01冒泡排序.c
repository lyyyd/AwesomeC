#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


typedef void(*func)(void*, int);
//typedef void(func)(void*, int);

typedef struct
{
	int id;
	char name[21];
	int age;
	char sex;
	int score;
	char addr[51];
}stu;

void SortDouble(void* arr, int len)
{
	double* p = (double*)arr;

	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (p[j] > p[j + 1])
			{
				double temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
void SortInt(void* arr,int len)
{
	int* p = (int*)arr;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
void SortStruct(void* arr, int len)
{
	stu* p = (stu*)arr;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p[j].age > p[j + 1].age)
			{
				stu temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}


//void BubbleSort(void* arr, int len, void(*p)(void*, int))
void BubbleSort(void* arr,int len,func p)
{
	p(arr, len);
}
int main0101()
{

	int arr[] = { 9,1,5,6,10,8,3,7,2,4 };
	BubbleSort(arr, 10, SortInt);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	return EXIT_SUCCESS;
}

int main0102()
{
	double arr[] = { 9.2,1.5,5.1,6.7,10.0,8.3,3.7,7.2,2.1,4.8 };
	BubbleSort(arr, 10, SortDouble);
	for (int i = 0; i < 10; i++)
	{
		printf("%.1lf\n", arr[i]);
	}
	return 0;
}

int main0103()
{
	stu arr[]=
	{
		{ 1001,"法师",32,'M',70,"黑龙江大庆" },
		{ 1003,"淼淼",20,'F',81,"山东菏泽" },
		{ 1007,"惠惠",18,'F',92,"安徽六安" },
		{ 1002,"盖伦",51,'M',66,"德玛西亚" },
		{ 1004,"劫",6,'M',30,"暗影岛" }
	};
	BubbleSort(arr, 5, SortStruct);

	for (int i = 0; i < 5; i++)
	{
		printf("%d  %s  %d  %s  %d  %s\n",
			arr[i].id, arr[i].name, arr[i].age,
			arr[i].sex == 'M' ? "男" : "女",
			arr[i].score, arr[i].addr);
	}
	return 0;
}

int main0104()
{
	int arr[] = { 9,1,5,6,10,8,3,7,2,4 };
	//在函数中定义函数指针类型变量
	void(*p)(void*, int) = SortInt;

	p(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	return EXIT_SUCCESS;
}