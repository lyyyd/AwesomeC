#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct LINKNODE
{
    //数据域
    int data;
    //指针域 将本结构体指针作为成员
    struct LINKNODE* next;
}linknode;

int main01()
{
    //静态链表

    //创建节点  栈区
    linknode s1 = { 1001,NULL };
    linknode s2 = { 1008,NULL };
    linknode s3 = { 1010,NULL };

    //建立关系
    s1.next = &s2;
    s2.next = &s3;

    //定义临时节点 用来遍历链表数据
    linknode* node = &s1;
    //打印链表数据
    while (node != NULL)
    {
        //打印数据
        printf("%d\n", node->data);
        //遍历下一个节点
        node = node->next;
    }

    return EXIT_SUCCESS;
}
