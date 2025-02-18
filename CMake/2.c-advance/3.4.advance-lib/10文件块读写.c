#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main1001()
{
    FILE* fp = fopen("D:/a.bin", "wb");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    //int a = 10;
    //fwrite(&a, sizeof(int), 1, fp);
    int arr[] = { 9,1,5,6,10,8,3,7,2,4 };
    fwrite(arr, sizeof(int), sizeof(arr) / sizeof(arr[0]), fp);
    fclose(fp);
    return EXIT_SUCCESS;
}


int main1002()
{
    FILE* fp = fopen("D:/a.bin", "rb");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    //int a;
    //fread(&a, sizeof(int), 1, fp);
    //printf("%d\n", a);

    int arr[10];
    fread(arr, sizeof(int), 10, fp);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    fclose(fp);
}