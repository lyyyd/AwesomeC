#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0901()
{
    FILE* fp = fopen("D:/c.txt", "w");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }

    //fprintf(fp, "%d+%d=%d", 1, 2, 3);
    fprintf(fp, "%d %f %s\n", 123, 3.14, "hello");

    fclose(fp);
    return EXIT_SUCCESS;
}


int main0902()
{
    FILE* fp = fopen("D:/c.txt", "r");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }

    //int a;
    //float b;
    //char arr[20];
    //fscanf(fp, "%d %f %s", &a, &b, arr);

    //printf("%d  %f  %s\n", a, b, arr);

    //获取文件中myname字符串
    char arr1[20];
    char arr2[20];
    //fscanf(fp, "%[^$]$%6s", arr1, arr2);
    fscanf(fp, "%8s%6s", arr1, arr2);
    printf("%s\n", arr2);
    fclose(fp);
    return 0;
}