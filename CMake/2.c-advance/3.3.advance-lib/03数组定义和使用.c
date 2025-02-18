#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 10
int main03()
{

    //数据类型 数组名[元素个数]={值1, 值2};
    //栈区数组
    //int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //for (int i = 0; i < sizeof(arr) / sizeof(arr[-1]); i++)
    //{
    //	///printf("%d\n", arr[i]);
    //	printf("%p\n", &arr[i]);
    //}
    /*
    数组元素个数  表示数组存储数据的最大值
    在C语言中，数组元素个数一定是一个常量

    下标是找到数组中具体元素位置
    下标是从0开始的到数组元素最大个数-1

    数组名【下标】  表示数据其中一个元素  相当于数据类型定义的一个变量

    数组的大小 sizeof(数组名)
    元素个数 sizeof(数组名)/sizeof(数组元素)
    */

    //int a = 10;

    //int arr[SIZE] = { 0 };

    int arr[] = { 4,8,2,9,1,5,7,3,10,6 };

    //数组元素个数
    int len = sizeof(arr) / sizeof(arr[0]);
    //冒泡排序
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
        }
    }

    for (int i = 0; i < len; i++)
        printf("%d\n", arr[i]);

    return EXIT_SUCCESS;
}
