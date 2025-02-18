#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main06()
{
    //fopen(文件位置 ，打开方式)
    //打开方式 r read w write a append  r+ w+ a+ rb wb ab rb+ wb+ ab+
    FILE* fp = fopen("D:/a.txt", "w");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return -1;
    }

    //操作文件

    //关闭文件
    fclose(fp);

    return EXIT_SUCCESS;
}
