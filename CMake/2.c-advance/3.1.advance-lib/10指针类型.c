#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{

    //指针变量指向内存地址编号为0的空间  操作空指针对应的内存空间会报错
    //int* p = NULL;//空指针
    //*p = 123;//err
    //printf("%d\n", *p);//err

    //int a = 10;
    //指针变量指向了一个未知的空间 操作该空间可能会报错
    //int* p = a;//野指针
    //int* p =0x007e3ff00;//野指针


    int* p = malloc(10);
    free(p);
    p = NULL;
    if (p == NULL)
    {
        printf("指针为NULL\n");
    }

    //操作也指着对应的堆空间
    //*p = 123;
    //printf("%d\n", *p);
    //printf("%p\n", p);

    return EXIT_SUCCESS;
}
