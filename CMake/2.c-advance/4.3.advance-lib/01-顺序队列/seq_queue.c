#include "seq_queue.h"


//初始化
queue_t *queue_init(int capacity)
{
    queue_t *q = NULL;

    //初始化
    q = darr_init(capacity);

    return q;
}

//入队列  在动态数组最后插入一个元素
int queue_en(queue_t *q, void *data)
{
    //1. 参数检查
    if (NULL == q || NULL == data)
    {
        printf("参数非法\n");
        goto err0;
    }

    //2. 尾插
    darr_insert_by_index(q, q->count, data);

    return 0;
    err0:
        return -1;
}

//出队列 删除动态数组第一个元素
int queue_de(queue_t *q, void **data)
{
    //1. 参数检查
    if (NULL == q || NULL == data)
    {
        printf("参数非法\n");
        goto err0;
    }

    *data = q->data[0];

    //2. 删除动态数组第一个元素
    darr_delete_by_index(q, 0);

    return 0;
    err0:
        return -1;
}

//返回对头元素
int queue_front(queue_t *q, void **data)
{
    //1. 参数检查
    if (NULL == q || NULL == data)
    {
        printf("参数非法\n");
        goto err0;
    }

    *data = q->data[0];

    return 0;
    err0:
        return -1;
}

//队列元素个数
int queue_count(queue_t *q)
{
    //1. 参数检查
    if (NULL == q)
    {
        printf("参数非法\n");
        goto err0;
    }

    return q->count;
    err0:
        return -1;
}

//判断队列是否为空
int queue_is_empty(queue_t *q)
{
    //1. 参数检查
    if (NULL == q)
    {
        printf("参数非法\n");
        goto err0;
    }

    //如果队列为空 就返回0 不为空就返回非零
    return !(0 == q->count);
    err0:
        return -1;
}

//销毁
int queue_destroy(queue_t *q)
{
    //1. 参数检查
    if (NULL == q)
    {
        printf("参数非法\n");
        goto err0;
    }

    darr_destroy(q);

    return 0;
    err0:
        return -1;
}


