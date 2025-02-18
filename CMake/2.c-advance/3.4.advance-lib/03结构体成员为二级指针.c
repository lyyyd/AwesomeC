#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
typedef struct
{
    int id:2;
    char name[21];
    //二级指针作为结构体成员
    int** score; //语文 数学 英语  平时 期中  期末
}student;
int main03()
{
    student stu;
    stu.id = 1001;
    strcpy(stu.name, "艾希");
    stu.score = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++)
    {
        stu.score[i] = (int*)malloc(sizeof(int) * 3);
    }
    //平时成绩
    stu.score[0][0] = 78;
    stu.score[0][1] = 92;
    stu.score[0][2] = 80;

    //期中成绩
    stu.score[1][0] = 94;
    stu.score[1][1] = 89;
    stu.score[1][2] = 91;

    //期末成绩
    stu.score[2][0] = 100;
    stu.score[2][1] = 100;
    stu.score[2][2] = 100;

    printf("编号：%d   姓名：%s\n成绩：\n", stu.id, stu.name);

    for (size_t i = 0; i < 3; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < 3; j++)
        {
            sum += stu.score[i][j];
            printf("%d  ", stu.score[i][j]);
        }
        printf("\t\t总和：%d",sum);
        printf("\n");
    }


    //堆空间释放

    for (int i = 0; i < 3; i++)
    {
        free(stu.score[i]);
    }
    free(stu.score);
    return EXIT_SUCCESS;
}
