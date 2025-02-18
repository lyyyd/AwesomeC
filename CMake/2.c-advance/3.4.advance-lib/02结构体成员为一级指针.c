#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct
{
    int id;
    //结构体成员为一级指针
    char* name;
    int age;
    char* addr;
}student;
int main02()
{
    //定义结构体变量
    student stu;
    //开辟结构体成员对应的堆空间
    stu.name = (char*)malloc(sizeof(char) * 21);
    stu.addr = (char*)malloc(sizeof(char) * 51);

    strcpy(stu.name, "盖伦");
    stu.id = 1001;
    stu.age = 32;
    strcpy(stu.addr, "德玛西亚");


    //结构体 变量赋值  浅拷贝  拷贝的是内存地址  深拷贝 拷贝的是内容
    student s = stu;
    //开辟结构体变量s对应的成员空间
    s.name = (char*)malloc(21);
    s.addr = (char*)malloc(51);
    strcpy(s.name, stu.name);//拷贝内容
    strcpy(s.addr, stu.addr);//拷贝内容
    //s.id = 1008;
    strcpy(s.name, "亚索");

    printf("s    :%d  %s  %d  %s\n", s.id, s.name, s.age, s.addr);
    printf("stu  :%d  %s  %d  %s\n", stu.id, stu.name, stu.age, stu.addr);

    //释放堆空间
    free(stu.name);
    free(stu.addr);

    free(s.name);
    free(s.addr);

    return EXIT_SUCCESS;
}
