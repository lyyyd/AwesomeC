#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



//void test03(int** arr, int row, int col)//err
//二维数组作为函数参数退化为指针，丢失了行和列的精度
//需要传递给形参列的精度  和行列的个数
//void test03(int* arr[3], int row, int col)//err
//指针数组作为函数参数也会丢失列的精度
//void test03(int arr[3][3], int row, int col)//ok
//void test03(int arr[][3], int row, int col)//ok
void test03(int (*arr)[3], int row, int col)//ok 数组指针
{
    printf("%d\n", sizeof(arr));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

int main07()
{
    int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
    test03(arr,3,3);

    return EXIT_SUCCESS;
}
