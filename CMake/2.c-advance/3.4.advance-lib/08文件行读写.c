#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0801()
{
    FILE* fp = fopen("D:/a.txt", "r");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }

    char* buf = (char*)malloc(100);

    //fgets(buf, 100, fp);
    //feof(文件指针)  如果到文件结尾 返回值为非0  如果没到文件末尾 值为0
    while (1)
    {
        memset(buf, 0, 100);
        fgets(buf, 100, fp);
        printf("%s", buf);
        if (feof(fp))
            break;
    }

    //printf("%s", buf);


    free(buf);
    fclose(fp);

    return EXIT_SUCCESS;
}


int main0802()
{
    FILE* fp = fopen("D:/b.txt", "w");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    char* arr[] = { "hello\n","world\n","你瞅啥" };

    //fputs(arr[0], fp);
    for (int i = 0; i < 3; i++)
    {
        fputs(arr[i], fp);
    }
    fclose(fp);
    return 0;
}