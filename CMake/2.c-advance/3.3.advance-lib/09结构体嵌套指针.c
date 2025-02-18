#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct stu
{
    //结构体成员为指针 需要开辟堆空间和释放堆空间
    char* name;
    int age;
    int* scores;
}ss;
int main0901()
{
    ss s1;
    //s1.name = "张三";//err
    s1.name = (char*)malloc(sizeof(char) * 21);
    strcpy(s1.name, "张三");
    s1.age = 18;
    s1.scores = (int*)malloc(sizeof(int) * 3);
    s1.scores[0] = 100;
    s1.scores[1] = 99;
    s1.scores[2] = 98;

    printf("姓名：%s\n年龄：%d\n成绩1：%d\n成绩2：%d\n成绩3：%d\n",
        s1.name, s1.age, s1.scores[0], s1.scores[1], s1.scores[2]);


    free(s1.name);
    free(s1.scores);
    return EXIT_SUCCESS;
}
int main0902(void)
{
    //创建结构体指针对应的堆空间
    ss* s1 = (ss*)malloc(sizeof(ss) * 3);

    for (int i = 0; i < 3; i++)
    {
        //结构体成员开辟堆空间
        s1[i].name = (char*)malloc(sizeof(char) * 21);
        s1[i].scores = (int*)malloc(sizeof(int) * 3);

        scanf("%s%d%d%d%d", s1[i].name, &s1[i].age,
            &s1[i].scores[0], &s1[i].scores[1], &s1[i].scores[2]);
    }

    for (int i = 0; i < 3; i++)
    {

        printf("姓名：%s\n年龄：%d\n成绩1：%d\n成绩2：%d\n成绩3：%d\n",
            s1[i].name, s1[i].age, s1[i].scores[0], s1[i].scores[1], s1[i].scores[2]);
    }

    for (int i = 0; i < 3; i++)
    {
        free(s1[i].name);
        free(s1[i].scores);
    }

    free(s1);
}