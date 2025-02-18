#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef void(*op_t)(void *data);

//节点类型
typedef struct _node_t {
    void *data;  //数据域
    struct _node_t *next; //指针域
}node_t;


//头信息结构体 管理队列
typedef struct _queue_t {
    node_t *front; //队头指针
    node_t *rear; //队尾指针
    int size;	//元素大小
    int count;	//元素个数
    op_t my_destroy; //自定义销毁函数
}queue_t;

//初始化
queue_t *queue_init(int size, op_t my_destroy);

//入队列
int queue_en(queue_t *q, void *data);

//出队列
int queue_de(queue_t *q, void *data);

//返回队头元素
int queue_front(queue_t *q, void *data);

//队列元素个数
int queue_count(queue_t *q);

//判空
int queue_is_empty(queue_t *q);

//销毁
int queue_destroy(queue_t *q);