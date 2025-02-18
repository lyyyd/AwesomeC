#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main08()
{
    //指针数组
    int** p = (int**)malloc(sizeof(int*) * 3);

    for (int i = 0; i < 3; i++)
    {
        p[i] = (int*)malloc(sizeof(int) * 4);
    }

    //外层控制行
    for (size_t i = 0; i < 3; i++)
    {
        //内层控制列
        for (int j = 0; j < 4; j++)
        {
            p[i][j] = i + j;
        }
    }
    //打印数据
    for (size_t i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d  ", p[i][j]);
        }
        printf("\n");
    }

    //释放堆空间
    for (int i = 0; i < 3; i++)
    {
        free(p[i]);
    }
    free(p);
    p = NULL;
    return EXIT_SUCCESS;
}
