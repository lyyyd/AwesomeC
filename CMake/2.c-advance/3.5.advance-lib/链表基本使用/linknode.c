#define _CRT_SECURE_NO_WARNINGS
#include "linknode.h"
#include<stdlib.h>
#include<stdio.h>

//创建链表
linknode * CreateLinkList()
{
    //创建头节点
    linknode* head = (linknode*)malloc(sizeof(linknode));
    head->data = -1;//-1为无效数据
    head->next = NULL;

    //创建临时节点
    linknode* temp = head;

    int value = 0;
    //录入链表数据
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
            break;

        //创建节点存储数据
        linknode* newnode = (linknode*)malloc(sizeof(linknode));
        //为数据域赋值
        newnode->data = value;
        //为指针域赋值
        newnode->next = NULL;

        //建立关系
        temp->next = newnode;
        //指向新节点
        temp = newnode;

    }

    return head;
}

//打印链表
void ForeachLinkList(linknode * head)
{
    if (head == NULL)
    {
        return;
    }
    linknode* temp = head->next;//数据节点
    while (temp != NULL)
    {
        //打印数据
        printf("%d\n", temp->data);
        //指向下一个节点
        temp = temp->next;
    }

}
//插入数据
int InsertLinkNode(linknode * head, int index, int data)
{
    if (head == NULL || index < 0)
    {
        return -1;
    }
    int i = 0;
    linknode* temp = head;
    //linknode* temp = head->next;//有效数据
    while (temp != NULL)
    {
        if (i == index)
        {
            linknode* newnode = (linknode*)malloc(sizeof(linknode));
            //为数据赋值
            newnode->data = data;
            newnode->next = NULL;

            //建立关系
            newnode->next = temp->next;
            temp->next = newnode;

            return 0;
        }
        //指向下一个节点
        temp = temp->next;
        i++;
    }

    return -1;
}
//删除数据
int DeleteLinkNode(linknode * head, int index)
{
    if (head == NULL || index <= 0)
    {
        return -1;
    }
    //当前节点
    linknode* temp = head->next;
    //前一个节点
    linknode* prev = head;

    int i = 1;
    while (temp != NULL)
    {
        if (index == i)
        {
            //建立关系
            prev->next = temp->next;
            //删除节点
            free(temp);
            return 0;
        }
        //前一个节点为当前节点
        prev = temp;
        //当前节点为下一个节点
        temp = temp->next;
        i++;
    }

    return -1;
}
//销毁链表
void DestroyLinkList(linknode * head)
{
    if (head == NULL)
        return;
    linknode* node = head;
    while (node != NULL)
    {
        linknode* temp = node->next;
        free(node);
        node = temp;
    }
}
