#pragma once

#include "darr.h"

//类型别名
typedef darr_t queue_t;

//初始化
queue_t *queue_init(int capacity);

//入队列
int queue_en(queue_t *q, void *data);

//出队列
int queue_de(queue_t *q, void **data);

//返回对头元素
int queue_front(queue_t *q, void **data);

//队列元素个数
int queue_count(queue_t *q);

//判断队列是否为空
int queue_is_empty(queue_t *q);

//销毁
int queue_destroy(queue_t *q);



