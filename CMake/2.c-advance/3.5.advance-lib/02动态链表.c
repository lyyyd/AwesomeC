#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


typedef struct LINKNODE
{
    //数据域
    int id;
    char name[21];
    //指针域
    struct LINKNODE* next;
    struct LINKNODE* front;
}linknode;

int main02()
{
    //动态链表  堆区
    //创建节点
    linknode* s1 = (linknode*)malloc(sizeof(linknode));
    s1->id = 1001;
    strcpy(s1->name, "盖伦");
    s1->next = NULL;
    s1->front = NULL;

    linknode* s2 = (linknode*)malloc(sizeof(linknode));
    s2->id = 1002;
    strcpy(s2->name, "亚索");
    s2->next = NULL;
    s2->front = NULL;

    linknode* s3 = (linknode*)malloc(sizeof(linknode));
    s3->id = 1003;
    strcpy(s3->name, "劫");
    s3->next = NULL;
    s3->front = NULL;

    //建立关系
    s1->next = s2;
    s2->next = s3;
    //s3->next = s1;

    //建立关系
    //s1->front = NULL;
    s2->front = s1;
    s3->front = s2;

    //创建临时节点 打印数据
    linknode* temp = s1;

    while (temp != NULL)
    {
        //打印数据
        printf("id:%d  name:%s\n", temp->id, temp->name);
        //指向下一个节点
        temp = temp->next;
    }



    //释放堆空间
    //free(s1);
    //free(s2);
    //free(s3);

    //循环释放堆空间
    linknode* node = s1;
    while (node != NULL)
    {
        //记录下一个节点
        linknode* temp = node->next;
        free(node);
        node = temp;
    }

    return EXIT_SUCCESS;
}
