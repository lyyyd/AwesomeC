#include "queue.h"


//初始化
queue_t *queue_init(int size, op_t my_destroy)
{
	queue_t *q = NULL;

	//1. 参数检查
	if (size <= 0)
	{
		printf("size 非法\n");
		goto err0;
	}

	//2. 分配空间
	q = malloc(sizeof(queue_t ));
	if (NULL == q)
	{
		printf("malloc queue_t 失败...\n");
		goto err0;
	}
	memset(q, 0, sizeof(queue_t));

	//3. 赋值
	q->front = NULL;
	q->rear = NULL;
	q->size = size;
	q->count = 0;
	q->my_destroy = my_destroy;

	return q;
err0:
	return NULL;
}

//入队列 尾插法
int queue_en(queue_t *q, void *data)
{
	node_t *new = NULL;

	//1. 参数检查
	if (NULL == q || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 分配节点空间
	new = malloc(sizeof(node_t));
	if (NULL == new)
	{
		printf("分配new失败...\n");
		goto err0;
	}
	memset(new, 0, sizeof(node_t));

	//3. 分配数据域空间
	new->data = malloc(q->size);
	if (NULL == new->data)
	{
		printf("分配new->data失败...\n");
		goto err1;
	}
	memset(new->data, 0, q->size);

	//拷贝数据
	memcpy(new->data, data, q->size);
	new->next = NULL;

	//4. 尾插
	if ((NULL == q->front) && (NULL == q->rear))
	{
		//队列开始没有任何节点情形
		q->front = new;
		q->rear = new;
	}
	else
	{
		//链表的最后一个节点的后继是new
		q->rear->next = new;

		//队列队尾指针指向链表最后一个节点
		q->rear = new;
	}

	//5. 改变count
	q->count++;

	return 0;
err1:
	free(new);
err0:
	return -1;
}

//出队列 删除链表的第一个节点
int queue_de(queue_t *q, void *data)
{
	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == q || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//判断队列是否为空
	if (NULL == q->front)
	{
		printf("队列为空..\n");
		goto err0;
	}

	//2. 删除 删除链表的第一个节点
	if (1 == q->count)
	{
		//队列中只有一个节点情形
		tmp = q->front;

		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		tmp = q->front;

		//队头指针指向新的第一个节点
		q->front = tmp->next;
	}

	//拷贝数据
	memcpy(data, tmp->data, q->size);

	//3. 释放内存
	if (NULL != q->my_destroy)
	{
		q->my_destroy(tmp->data);
	}
	free(tmp->data);
	free(tmp);

	//4. count减1
	q->count--;

	return 0;
err0:
	return -1;
}

//返回队头元素
int queue_front(queue_t *q, void *data)
{
	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == q || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//判断队列是否为空
	if (NULL == q->front)
	{
		printf("队列为空....\n");
		goto err0;
	}

	//2. 拷贝数据
	tmp = q->front;
	memcpy(data, tmp->data, q->size);

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

//判空
int queue_is_empty(queue_t *q)
{
	//1. 参数检查
	if (NULL == q)
	{
		printf("参数非法\n");
		goto err0;
	}

	//如果为空就返回0 否则返回非零
	return !(0 == q->count);
err0:
	return -1;
}

//销毁
int queue_destroy(queue_t *q)
{
	node_t *tmp = NULL;
	node_t *save = NULL;

	//1. 参数检查
	if (NULL == q)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 依次释放节点数据域其它空间

	tmp = q->front;
	while (tmp)
	{
		//保存下一个节点
		save = tmp->next;

		if (NULL != q->my_destroy)
		{
			q->my_destroy(tmp->data);
		}

		//释放数据域空间
		free(tmp->data);

		//释放节点空间
		free(tmp);

		//重新复制
		tmp = save;
	}

	free(q);

	return 0;
err0:
	return -1;
}


