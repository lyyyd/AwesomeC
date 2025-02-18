#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    //一般用于错误日志log记录
    printf("%s\n", __FILE__);//文件名
    printf("%d\n", __LINE__);//文件行号
    printf("%s\n", __DATE__);//编译日期
    printf("%s\n", __TIME__);//编译时间

    system("pause");
    return EXIT_SUCCESS;
}
