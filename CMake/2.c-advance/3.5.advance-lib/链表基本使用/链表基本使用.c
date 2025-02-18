#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"linknode.h"

int main()
{
    //创建链表
    linknode* list = CreateLinkList();

    //打印链表
    ForeachLinkList(list);
    printf("-----------\n");
    //插入节点
    int result = InsertLinkNode(list, 1, 555);
    if (result == 0)
        printf("数据插入成功\n");
    else
        printf("数据插入失败\n");

    //打印链表
    ForeachLinkList(list);
    printf("-----------\n");

    //删除节点
    result = DeleteLinkNode(list, 3);
    if (result == 0)
        printf("数据删除成功\n");
    else
        printf("数据删除失败\n");
    //打印链表
    ForeachLinkList(list);
    printf("-----------\n");

    //销毁链表
    DestroyLinkList(list);

    return EXIT_SUCCESS;
}
