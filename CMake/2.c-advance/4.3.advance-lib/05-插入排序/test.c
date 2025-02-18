#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//数组初始化
int arr_init(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        //1---100
        a[i] = rand() % 100 + 1;
    }

    return 0;
}

//数组输出
int arr_print(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

//编程珠玑

//插入排序
int insert_sort(int *a, int n)
{
    int i, j;
    int tmp = 0;

    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && tmp < a[j]; j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = tmp;
    }

    return 0;
}

int main()
{
    int a[10];

    //设置随机种子
    srand((unsigned int)time(NULL));

    //初始化
    arr_init(a, 10);
    //输出
    arr_print(a, 10);

    //排序
    insert_sort(a, 10);
    arr_print(a, 10);

    system("pause");
    return 0;
}
