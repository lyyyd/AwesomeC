#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct
{
    int id;
    char name[21];
    int age;
    char sex;
    char addr[51];
}student;
int main()
{
    //计算数据类型在内存中占的字节大小
    int a = 10;
    //sizeof(变量名) sizeof(数据类型) sizoef 变量名
    int len = sizeof a * 4;
    printf("%d\n", len);
    return EXIT_SUCCESS;
}

int main0302()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //数组在内存中占的字节大小
    printf("%d\n", sizeof(arr));
    return 0;
}

int main0303()
{
    printf("%d\n", sizeof(student));
    return 0;
}
