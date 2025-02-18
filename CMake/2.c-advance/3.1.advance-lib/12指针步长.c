#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    /*
    &arr[0]//变量地址 一级指针
    arr//一级指针
    &arr//二级指针
    */
    //定义指针指向数组
    int* p = arr;
    ////printf("%d\n", *p);
    //printf("%p\n", p);
    ////p = p + 1;//指针+1 指向数组下一个元素
    //p++;
    //printf("%p\n", p);
    //p--;
    //printf("%p\n", p);
    p = &arr[9];

    int step = p - arr;//计算两个指针之间元素个数
    printf("%d\n", step);

    return EXIT_SUCCESS;
}

int my_strlen(const char* str)
{
    char* temp = str;
    while (*temp)temp++;
    return temp - str;
}
int main1202()
{
    char str[] = "hello world";
    int len=my_strlen(str);
    printf("%d\n", len);

    return 0;
}
