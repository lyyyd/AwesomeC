#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main0601()
{
    //数据类型 数组名【行】【列】  二维数组在定义时可以省略行个数
    int arr[][4]=
    {
        {1,2,3,4},
        {2,3,4,5},
        {3,4,5,6}
    };
    //int arr[][3] = { 1,2,3,4,5,6,7,8,9,10,'j','q' };

    //行个数
    printf("%d\n", sizeof(arr) / sizeof(arr[0]));
    //列个数
    printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //printf("%d ", arr[i][j]);
            //打印二维数组所有地址
            //二维数组其实就是一个连续的一维数组

            printf("%p\n", &arr[i][j]);
        }
        //puts("");
    }

    return EXIT_SUCCESS;
}
int main0602()
{
    //栈区的二维数组其实是一个连续的一维数组
    int arr[][3] = { 1,2,3,4,5,6,7,8,9,10,'j','q' };
    int*p = arr;

    for (int i = 0; i < 3 * 4; i++)
        printf("%d\n", p[i]);

    //栈区二维数组排序时先可以转成一维数组进行排序


    /*
    1 2 3
    4 5 6
    7 8 9

    1 4 7
    2 5 8
    3 6 9

    二维数组转置

    */
    return 0;
}

int main0603()
{
    int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        puts("");
    }
    return 0;
}