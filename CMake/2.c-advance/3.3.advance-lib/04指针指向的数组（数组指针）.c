#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main0401()
{

    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //数组指针
    //数组名是一个常量
    //指针是一个变量
    int* p = arr;

    p++;
    printf("%d\n", *p);
    printf("%d\n", p[-1]);//*(p-1)
    //for (int i = 0; i < 10; i++)
    //{
    //	printf("%d\n", *(p + i));
    //	printf("%d\n", p[i]);
    //}

    return EXIT_SUCCESS;
}
int main0402(void)
{
    //数组指针
    int* p = (int*)malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < 10; i++)
        printf("%d\n", p[i]);

    free(p);
}

void test01(int* src,int len)
{
    //数组作为函数参数退化为指针，丢失列的精度  需要传递元素个数
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (src[j] > src[j + 1])
            {
                int temp = src[j];
                src[j] = src[j + 1];
                src[j + 1] = temp;
            }
        }
    }

}
int main0403(void)
{
    int arr[] = { 1,6,2,8,3,4,9,5,10,7 };

    test01(arr, 10);

    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);

    return 0;
}

int main0404(void)
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

    int* p = arr;

    //对数组名取地址是一个二级指针
    //数组取地址+1跳过整个数组
    int** p1 = &arr;

    printf("%p\n", p);
    printf("%p\n", p1);

    printf("%p\n", arr + 1);
    printf("%p\n", &arr + 1);
    //int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

    printf("%d\n", *(*(&arr + 1) - 2));

}