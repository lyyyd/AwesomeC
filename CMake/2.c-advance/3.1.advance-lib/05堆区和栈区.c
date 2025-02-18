#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

char* test1()
{
    //局部变量p在函数结束 数据信息从栈区内存销毁
    char p[] = "hello world";
    printf("%s\n", p);
    return p;
}
int main()
{
    char* p = NULL;

    //野指针
    p = test1();
    printf("%p\n", p);
    printf("%s\n", p);
    return EXIT_SUCCESS;
}


int main0502()
{
    //开辟堆空间
    //int* p = (int*)malloc(4);
    //*p = 10;
    int* p = (int*)malloc(sizeof(int) * 10);

    //堆空间赋值
    for (int i = 0; i < 10; i++)
    {
        //p[i] = i;
        *(p + i) = i;
    }


    for (int i = 0; i < 10; i++)
    {
        //printf("%d\n", p[i]);
        printf("%d\n", *(p + i));
    }
    //释放堆空间
    free(p);
    return 0;
}
