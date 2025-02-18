#include "stack.h"


//栈初始化
stack_t *stack_init(int size, int max, op_t my_destroy)
{
	stack_t *s = NULL;

	//1. 参数检查
	if (size <= 0 || max <= 0)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 分配空间
	s = calloc(1, sizeof(stack_t));
	if (NULL == s)
	{
		printf("calloc failed...\n");
		goto err0;
	}

	//分配栈空间(连续的存储空间)
	s->data = malloc(max * size);
	if (NULL == s->data)
	{
		printf("分配空间data 失败...\n");
		goto err1;
	}
	memset(s->data, 0, max * size);

	//3. 赋值
	s->top = 0;
	s->size = size;
	s->max = max;
	s->my_destroy = my_destroy;

	return s;
err1:
	free(s);
err0:
	return NULL;
}

//进栈
int stack_push(stack_t *s, void *data)
{
	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 判断栈是否满
	if (s->top == s->max)
	{
		printf("栈已经满了....\n");
		goto err0;
	}

	//3. 进栈
	memcpy((char*)s->data + s->size * s->top, data, s->size);

	//4. 改变栈顶的下标
	s->top++;


	return 0;
err0:
	return -1;
}

//出栈
int stack_pop(stack_t *s, void *data)
{
	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 判断栈是否为空
	if (0 == s->top)
	{
		printf("栈为空...\n");
		goto err0;
	}

	//3. 出栈
	memcpy(data, (char *)s->data + s->size * (s->top - 1), s->size);

	//4. 改变top
	s->top--;

	return 0;
err0:
	return -1;
}

//返回栈顶元素
int stack_top(stack_t *s, void *data)
{
	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 判断栈是否为空
	if (0 == s->top)
	{
		printf("栈为空...\n");
		goto err0;
	}

	//3. 返回栈顶元素
	memcpy(data, (char *)s->data + s->size * (s->top - 1), s->size);

	return 0;
err0:
	return -1;
}

//判断栈是否满
int stack_is_full(stack_t *s)
{
	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 判断
	//0 表示栈已经满了
	return !(s->top == s->max);
err0:
	return -1;
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

	//2. 判断
	//如果栈为空 就返回0
	return !(0 == s->top);
err0:
	return -1;
}

//返回栈中元素的个数
int stack_count(stack_t *s)
{
	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2.  返回值

	return s->top;
err0:
	return -1;
}



//栈的销毁
int stack_destroy(stack_t *s)
{
	int i = 0;
	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 依次释放内存
	if (NULL != s->my_destroy)
	{
		for (i = 0; i < s->top; i++)
		{
			s->my_destroy((char *)s->data + s->size * i);
		}
	}

	//3. 释放s->data
	free(s->data);

	//4. 释放s
	free(s);

	return 0;
err0:
	return -1;
}
