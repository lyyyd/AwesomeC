#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//结构体名
//struct stu
//{
//	//结构体成员列表  数据类型可以不相同
//	char name[21];
//	int age;
//}ss = { "张三",18 };//结构体变量名

struct scores
{
    int cl;
    int cpp;
    int cs;

};

//结构退不允许嵌套本结构体
typedef struct stu
{
    char name[21];//21
    int age;//4
    struct scores score;//12  总有效大小为37B  实际占用空间为40B
    //struct stu * stus;
}ss;//结构体别名


int main0801()
{
    //	struct stu ss;
    //	//ss.stus.stus.stus.stus//err
    //	printf("%d\n", sizeof(struct stu));

    //ss s1;
    ////s1.name = "张三";//err
    //strcpy(s1.name, "张三");
    //s1.age = 18;
    //s1.score.cl = 100;
    //s1.score.cpp = 90;
    //s1.score.cs = 80;
    //ss s1 = { "张三",18,100,90,80 };
    //char ch[] = "hello world";
    ss s1 = { .score.cl = 100,.age = 18,.name = "张三",.score.cs = 80,.score.cpp = 90 };

    printf("姓名：%s\n年龄：%d\n成绩1：%d\n成绩2：%d\n成绩3：%d\n",
        s1.name, s1.age, s1.score.cl, s1.score.cpp, s1.score.cs);


    return EXIT_SUCCESS;
}

int main0802(void)
{
    //结构体数组
    ss s1[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s%d%d%d%d", s1[i].name, &s1[i].age, &s1[i].score.cl,
            &s1[i].score.cpp, &s1[i].score.cs);
    }


    for (int i = 0; i < 3; i++)
    {
        printf("姓名：%s\n年龄：%d\n成绩1：%d\n成绩2：%d\n成绩3：%d\n",
            s1[i].name, s1[i].age, s1[i].score.cl, s1[i].score.cpp, s1[i].score.cs);
    }

}

int main0803(void)
{
    ss s1[] =
    {
        {"野生",17,100,100,100},
        {"嘉阳",20,88,66,44},
        {"豢养",30,99,90,9}
    };
    //struct stu *
    ss* p = s1;
    //结构体指针可以指向其成员
    //(p+i)->name

    for (int i = 0; i < 3; i++)
    {
        //printf("姓名：%s\n年龄：%d\n成绩1：%d\n成绩2：%d\n成绩3：%d\n",
        //	p[i].name, p[i].age, p[i].score.cl, p[i].score.cpp, p[i].score.cs);
        printf("姓名：%s\n年龄：%d\n成绩1：%d\n成绩2：%d\n成绩3：%d\n",
            (p+i)->name, (p+i)->age, (p+i)->score.cl, (p+i)->score.cpp, (p+i)->score.cs);
    }
}