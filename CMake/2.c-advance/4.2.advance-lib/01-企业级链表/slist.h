#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//函数指针类型
typedef void(*op_t)(void *data);

//节点类型
typedef struct _node_t {
    struct _node_t *next; //指针域
}node_t;

//头信息结构体类型
typedef struct _slist_t {
    node_t *p;	//指向链表的第一个节点
    int count;  //链表中节点个数
    op_t my_destroy;
}slist_t;

//初始化
slist_t *slist_init(op_t my_destroy);

//插入
int slist_insert_by_index(slist_t *s, void *data, int index);

//删除(index)
int slist_delete_by_index(slist_t *s, int index);

//遍历
int slist_traverse(slist_t *s, op_t my_print);

//销毁
int slist_destroy(slist_t *s);
