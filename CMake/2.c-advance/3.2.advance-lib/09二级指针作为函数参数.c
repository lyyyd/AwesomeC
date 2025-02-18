#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//二级指针作为函数参数
void demo(int** p1)
{
    *p1 = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        //(*p1)[i] = rand() % 100;
        //p1[0][i] = rand() % 100;
        *((*p1) + i) = rand() % 100;
    }
}

int main0901()
{
    srand((size_t)time(NULL));
    //输出特性 被调函数提供空间
    int * p = NULL;
    demo(&p);

    printf("%p\n", p);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);
    return EXIT_SUCCESS;
}

//二维数组作为函数参数 退化为指针丢失元素精度 需要传递行个数
//二级指针
//void sort(char **arr,int len)
//指针数组
void sort(char *arr[3], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            //根据首字母比较数据
            if (arr[j][0]>arr[j + 1][0])
            {
                //交换数据
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main0902()
{
    //输入特性
    //字符串数组  指针数组 二维数组  主调函数分配空间
    char* p[3] = { "hello","world","kitty" };
    sort(p,3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", p[i]);
    }
}