#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//声明函数指针类型
typedef void(*op_t)(void *data);

typedef int(*cmp_t)(void *data, void *key);

//节点类型声明
typedef struct _node_t {
    void *data; //数据域
    struct _node_t *next; //指针域
}node_t;


//头信息结构体声明
typedef struct _slist_t {
    node_t *p;	//指向链表的第一个节点
    int size;   //数据域元素大小
    int count;	//节点个数
}slist_t;


//链表初始化
slist_t *slist_init(int size);

//头插
int slist_prepend(slist_t *s, void *data);

//尾插
int slist_append(slist_t *s, void *data);

//指定位置插入
int slist_insert_by_index(slist_t *s, void *data, int index);

//链表的遍历
int slist_traverse(slist_t *s, op_t my_print);

//删除链表节点（索引）
int slist_delete_by_index(slist_t *s, int index);

//删除链表节点（关键字)
int slist_delete_by_key(slist_t *s, void *key, cmp_t my_cmp);

//返回链表节点个数
int slist_count(slist_t *s);

//链表的销毁
int slist_destroy(slist_t *s);