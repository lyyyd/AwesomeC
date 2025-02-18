#include "stack.h"

//初始化
stack_t *stack_init(int size, op_t my_destroy)
{
	stack_t *s = NULL;

	//1. 参数检查
	if (size < 0)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 分配空间
	s = malloc(sizeof(stack_t));
	if (NULL == s)
	{
		printf("malloc 失败...\n");
		goto err0;
	}
	memset(s, 0, sizeof(stack_t));

	//3. 赋值
	s->top = NULL;
	s->size = size;
	s->count = 0;
	s->my_destroy = my_destroy;

	return s;
err0:
	return NULL;
}

//进栈  头插法
int stack_push(stack_t *s, void *data)
{
	node_t *new = NULL;

	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 分配节点空间
	new = malloc(sizeof(node_t));
	if (NULL == new)
	{
		printf("malloc node_t 失败...\n");
		goto err0;
	}
	memset(new, 0, sizeof(*new));

	//3. 拷贝数据
	new->data = malloc(s->size);
	if (NULL == new->data)
	{
		printf("malloc data 失败...\n");
		goto err0;
	}
	memset(new->data, 0, s->size);
	memcpy(new->data, data, s->size);

	//4. 头插法
	//新节点后继指向原来链表第一个节点
	new->next = s->top;
	//栈顶指针指向新节点
	s->top = new;

	//5. count加1
	s->count++;


	return 0;
err0:
	return -1;
}

//出栈
int stack_pop(stack_t *s, void *data)
{
	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 判断栈是否为空
	if (0 == s->count)
	{
		printf("栈为空...\n");
		goto err0;
	}

	//3. 出栈  链表删除第一个节点
	tmp = s->top;

	s->top = tmp->next;

	//4. 释放内存
	memcpy(data, tmp->data, s->size);

	if (NULL != s->my_destroy)
	{
		s->my_destroy(tmp->data);
	}

	free(tmp->data);
	free(tmp);

	//5. count减1
	s->count--;

	return 0;
err0:
	return -1;
}

//返回栈顶元素
int stack_top(stack_t *s, void *data)
{
	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 判断栈是否为空
	if (0 == s->count)
	{
		printf("栈为空...\n");
		goto err0;
	}

	//3. 拷贝数据
	tmp = s->top;
	memcpy(data, tmp->data, s->size);

	return 0;
err0:
	return -1;
}

//返回栈中元素个数
int stack_count(stack_t *s)
{
	//1. 参数检查

	//2. 返回s->count

	return 0;
}

//判断栈是否为空
int stack_is_empty(stack_t *s)
{

	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	return s->count;
err0:
	return -1;
}

//销毁
int stack_destroy(stack_t *s)
{
	node_t *tmp = NULL;
	node_t *save = NULL;

	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 释放节点数据内存

	tmp = s->top;
	while (tmp)
	{
		//保存下一个节点
		save = tmp->next;
		if (NULL != s->my_destroy)
		{
			s->my_destroy(tmp->data);
		}

		free(tmp->data);
		free(tmp);

		//将下一个节点tmp
		tmp = save;

	}

	//释放信息结构体内存
	free(s);

	return 0;
err0:
	return -1;
}
