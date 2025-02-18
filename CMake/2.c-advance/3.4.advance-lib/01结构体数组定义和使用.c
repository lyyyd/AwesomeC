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
    char addr[51];
}student;
int main0101()
{
    //定义栈区结构体数组
    student arr[3] =
    {
        {1001,"法师",32,"黑龙江大庆"},
        {1002,"水哥",26,"山东菏泽"},
        {1003,"惠惠",31,"安徽六安"}
    };

    //结构体成员 数组名[下标].成员
    //(数组名+步长)->成员
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d  %s  %d  %s\n", arr[i].id, arr[i].name, arr[i].age, arr[i].addr);
        //printf("%d  %s  %d  %s\n", (arr + i)->id, (arr + i)->name, (arr + i)->age, (arr + i)->addr);
    }
    return EXIT_SUCCESS;
}


int main0102()
{
    //定义堆区结构体数组
    student* p = (student*)malloc(sizeof(student) * 3);

    //p[0].id = 1001;
    //strcpy(p[0].name, "法师");
    //p[0].age = 32;
    //strcpy(p[0].addr, "黑龙江大庆");
    //(结构体数据类型){结构体成员值}
    p[0] = (student) { 1001, "法师", 32, "黑龙江大庆" };
    p[1] = (student) { 1002, "淼淼", 26, "山东菏泽" };
    p[2] = (student) { 1003, "惠惠", 31, "安徽六安" };
    for (int i = 0; i < 3; i++)
    {
        printf("%d  %s  %d  %s\n", p[i].id, p[i].name, p[i].age, p[i].addr);
    }

    free(p);
    return 0;
}