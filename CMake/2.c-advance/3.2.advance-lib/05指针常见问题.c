#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0501()
{
    //下标越界
    //char str[10] = "helloworld";
    //printf("%s", str);

    int* p = malloc(10);//sizeof(数据类型)*个数
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;//数组下标越界
    free(p);
    return EXIT_SUCCESS;
}


int main0502()
{
    int* p = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *p);
        //指针不断叠加 会改变指针指向
        p++;
    }
    //p -= 10;
    //释放野指针对应的堆空间
    free(p);
    return 0;
}

char* test3()
{
    char arr[] = "hello world";
    return arr;
}

int main0503()
{
    char* p = NULL;
    //函数结束 函数信息从栈区内存销毁  不能读取内容
    //野指针
    p = test3();

    printf("%s\n", p);
    return 0;
}

int main0504()
{
    char* p = (char*)malloc(100);
    free(p);
    printf("%p\n", p);
    //建议使用空指针代替野指针
    //p = NULL;
    //指针释放多次 会报错
    free(p);
    return 0;
}