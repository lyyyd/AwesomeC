#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int* p = (int*)malloc(sizeof(int) * 10);
    //重置一块内存空间的值
    //memset(地址，值，字节大小)
    memset(p, 0, 40);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }
    free(p);
    return EXIT_SUCCESS;
}


int main0602()
{
    //使用calloc()开辟堆空间会自动初始化值为0
    int* p = (int*)calloc(10, sizeof(int));
    if (p == NULL)
    {
        printf("堆空间开辟失败\n");
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }

    free(p);
    return 0;
}

int main0603()
{
    char* p = (char*)malloc(sizeof(char) * 11);
    strcpy(p, "helloworld");
    //追加堆空间
    p = realloc(p, 20);
    strcat(p, "你瞅啥");
    printf("%s\n", p);
    free(p);
    return 0;
}

int main0604()
{
    int* p = NULL;
    //开辟一个新空间
    p = (int*)realloc(p, sizeof(int) * 10);

    memset(p, 0, 40);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }

    free(p);
    return 0;

}