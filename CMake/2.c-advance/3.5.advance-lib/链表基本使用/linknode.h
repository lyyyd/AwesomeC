#pragma once
//创建链表结构体
typedef struct LINKNODE
{
    //数据域
    int data;
    //指针域
    struct LINKNODE* next;
}linknode;

//创建链表 返回值为头节点
extern linknode* CreateLinkList();
//遍历链表
extern void ForeachLinkList(linknode* head);
//插入节点  参数：
extern int InsertLinkNode(linknode* head,int index,int data);
//删除节点
extern int DeleteLinkNode(linknode* head,int index);
//销毁链表
extern void DestroyLinkList(linknode* head);

