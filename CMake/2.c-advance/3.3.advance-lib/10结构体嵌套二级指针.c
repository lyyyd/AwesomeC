#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*
张三 18
9 9 9
10 10 10
8 8 8

李四 20
7 7 7
9 8 9
10 1 10

王五 31
6 6 6
2 2 2
10 9 8

*/
typedef struct stu
{
    char* name;
    int age;
    int** scores;//期中成绩  期末成绩 平时成绩
}ss;
int main10()
{
    //开辟结构体数组对应的对空间
    ss* s1 = (ss*)malloc(sizeof(ss) * 3);

    for (int i = 0; i < 3; i++)
    {
        //存储学生姓名
        s1[i].name = (char*)malloc(sizeof(char) * 21);
        //存储学生期中成绩  期末成绩 平时成绩类型
        s1[i].scores = (int**)malloc(sizeof(int*) * 3);
        for (int j = 0; j < 3; j++)
        {
            //存储学生三门成绩
            s1[i].scores[j] = (int*)malloc(sizeof(int) * 3);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        printf("请输入姓名年龄成绩\n");
        scanf("%s%d", s1[i].name, &s1[i].age);

        //期中成绩0  期末成绩1 平时成绩2
        for (int j = 0; j < 3;j++)
            //cl cpp cs
                scanf("%d%d%d", &s1[i].scores[j][0], &s1[i].scores[j][1], &s1[i].scores[j][2]);
    }


    for (int i = 0; i < 3; i++)
    {
        printf("姓名：%s\n年龄：%d\n", s1[i].name, s1[i].age);
        for (int j = 0; j < 3; j++)
            printf("成绩：cl:%d cpp:%d cs:%d\n",
                 s1[i].scores[j][0], s1[i].scores[j][1], s1[i].scores[j][2]);
    }


    //释放
    for (int i = 0; i < 3; i++)
    {
        free(s1[i].name);
        for (int j = 0; j < 3; j++)
        {
            free(s1[i].scores[j]);
        }
        free(s1[i].scores);
    }
    free(s1);

    return EXIT_SUCCESS;
}
