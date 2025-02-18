#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main0501()
{
    //野指针
    //int* arr[] = { 10,20,30 };

    //for (int i = 0; i < 3; i++)
    //{
    //	printf("%d\n", *arr[i]);
    //}

    //int a = 10;
    //int b = 20;
    //int c = 30;

    //int* arr[] = { &a,&b,&c };

    //for (int i = 0; i < 3; i++)
    //	//printf("%d", *arr[i]);
    //	printf("%d", **(arr+i));


    int a[] = { 1,2,3 };
    int b[] = { 2,3,4 };
    int c[] = { 4,5,6 };

    //int* arr[] = { &a,&b,&c };//err
    int* arr[] = { a,b,c };//ok
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);

    return EXIT_SUCCESS;
}
int main0502(void)
{
    srand((unsigned int)time(NULL));
    //二级指针对应的堆空间

    int** p = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++)
        //p[i] = (int*)malloc(sizeof(int) * 3);
            *(p+i) = (int*)malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            p[i][j] = rand() % 100;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            printf("%d\n", p[i][j]);
}