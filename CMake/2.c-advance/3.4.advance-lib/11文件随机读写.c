#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main1101()
{
    FILE* fp = fopen("D:/a.txt", "r");
    if (!fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    //偏移位置：
    //SEEK_SET  从起始位置开始偏移
    //SEEK_CUR  从当前位置开始偏移
    //SEEK_END  从文件末尾开始偏移
    fseek(fp,20,SEEK_SET);

    char buf[100];
    fgets(buf, 100, fp);
    printf("%s", buf);


    fseek(fp, 20, SEEK_CUR);
    fgets(buf, 100, fp);
    printf("%s", buf);

    //ftell(文件指针)  计算文件起始位置到当前的字符个数

    //long len = ftell(fp);
    //printf("%d\n", len);

    //计算整个文件字符个数
    //将文件光标流置为文件末尾
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    printf("%ld\n", len);

    //将文件光标流置为文件起始位置
    rewind(fp);
    //fseek(fp, 0, SEEK_SET);
    len = ftell(fp);
    printf("%ld\n", len);
    fclose(fp);

    return EXIT_SUCCESS;
}
