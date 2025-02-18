#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main1401()
{
    srand((unsigned int)time(NULL));
    //# ASCII 35  0010 0011

    //0000 0000 0000 0000
    //0001 0001 1000 0000 << 7
    //0000 0010 0011 0000

    FILE* fp1 = fopen("D:/config.ini", "r");
    FILE* fp2 = fopen("D:/加密文件.ini", "w");
    if (!fp1 || !fp2)
    {
        printf("文件加密失败\n");
        return 0;
    }
    short ch;
    while ((ch=fgetc(fp1))!=EOF)
    {
        //左移7位
        ch = ch << 7;
        //添加随机数作为混淆
        ch += rand() % 128;
        //printf("%hd\n", -ch);
        //写入文件中
        fprintf(fp2, "%hd", -ch);
    }
    fclose(fp1);
    fclose(fp2);


    return EXIT_SUCCESS;
}


int main()
{
    FILE* fp1 = fopen("D:/加密文件.ini", "r");
    FILE* fp2 = fopen("D:/解密文件.ini", "w");
    if (!fp1 || !fp2)
    {
        printf("文件加密失败\n");
        return 0;
    }
    short ch;
    while (!feof(fp1))
    {
        fscanf(fp1, "%hd", &ch);
        ch = -ch;
        ch = ch >> 7;
        //printf("%c", ch);
        fputc((char)ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}