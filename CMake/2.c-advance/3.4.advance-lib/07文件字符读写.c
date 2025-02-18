#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//字符写入文件
int main0701()
{
    FILE* fp = fopen("D:/a.txt", "w");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }

    //字符写入文件
    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);

    fclose(fp);
    return EXIT_SUCCESS;
}

//字符读取文件
int main0702()
{
    FILE *fp = fopen("D:/a.txt", "r");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }


    //字符读取
    char ch;
    ch = fgetc(fp);
    printf("%c", ch);

    ch = fgetc(fp);
    printf("%c", ch);

    ch = fgetc(fp);
    printf("%c", ch);
    fclose(fp);
    return 0;
}

int main0703()
{
    FILE *fp = fopen("D:/a.txt", "r");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }

    //EOF  文件结束标志

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}