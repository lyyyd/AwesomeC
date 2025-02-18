#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main12()
{

    FILE* fp = fopen("D:/d.txt", "w");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    char ch;
    while (1)
    {
        ch = getchar();
        if (ch == ':')
            break;
        fputc(ch, fp);
        //更新文件缓冲区
        fflush(fp);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
