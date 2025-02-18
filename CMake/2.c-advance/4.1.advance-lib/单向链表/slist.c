#include "slist.h"

//链表初始化
slist_t *slist_init(int size)
{
	slist_t *s = NULL;

	//1. 参数检查
	if (size <= 0)
	{
		printf("The size is invalid\n");
		goto err0;
	}

	//2. 分配空间
	s = malloc(sizeof(slist_t));
	if (NULL == s)
	{
		printf("malloc slist_t failed..\n");
		goto err0;
	}
	memset(s, 0, sizeof(slist_t));

	//3. 赋初值
	s->p = NULL;
	s->size = size;
	s->count = 0;

	return s;
err0:
	return NULL;
}

//分配节点空间 和拷贝数据
static void * __node_malloc(slist_t *s, void *data)
{
	node_t *new = NULL;

	//0. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//1. 分配新节点空间
	new = malloc(sizeof(node_t));
	if (NULL == new)
	{
		printf("malloc new failed...\n");
		goto err0;
	}
	memset(new, 0, sizeof(node_t));

	//2. 分配数据空间
	new->data = malloc(s->size);
	if (NULL == new->data)
	{
		printf("malloc data failed...\n");
		goto err0;
	}
	memset(new->data, 0, s->size);

	//拷贝数据
	memcpy(new->data, data, s->size);
	new->next = NULL;

	//3. 元素个数加1
	s->count++;

	return new;
err0:
	return NULL;
}

//头插
int slist_prepend(slist_t *s, void *data)
{
	node_t *new = NULL;

	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 分配节点空间和拷贝数据
	new = __node_malloc(s, data);
	if (NULL == new)
	{
		goto err0;
	}

	//3. 头插
	new->next = s->p; //新节点后继节点是链表原来的第一个节点
	s->p = new; //s->p指向新节点


	return 0;
err0:
	return -1;
}

//尾插
int slist_append(slist_t *s, void *data)
{
	node_t *tmp = NULL;
	node_t *new = NULL;

	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}
	//2. 分配节点空间
	new = __node_malloc(s, data);
	if (NULL == new)
	{
		printf("malloc new failed..\n");
		goto err0;
	}

	//3. 找到链表最后一个节点
	if (NULL == s->p)
	{
		//链表本身为空链表情形
		s->p = new;
	}
	else
	{
		tmp = s->p; //指向链表的第一个节点
		while (NULL != tmp->next)
		{
			//指向下一个节点
			tmp = tmp->next;
		}

		//4. 尾插
		tmp->next = new;
	}

	return 0;
err0:
	return -1;
}

//指定位置插入
int slist_insert_by_index(slist_t *s, void *data, int index)
{
	int i = 0;

	node_t *tmp = NULL;
	node_t *new = NULL;

	//1. 参数检查
	if (NULL == s || NULL == data)
	{
		printf("参数非法\n");
		goto err0;
	}

	if (index < 0 || index > s->count)
	{
		//索引非法 直接尾插
		index = s->count;
	}

	//2. 分配节点空间 拷贝数据
	new = __node_malloc(s, data);
	if (NULL == new)
	{
		goto err0;
	}

	//3. 找到插入位置前一个节点

	if (0 == index)
	{
		//新节点后继为原来链表的第一个节点
		new->next = s->p;

		//s->p 指向链表的第一个节点
		s->p = new;
	}
	else
	{
		tmp = s->p; //指向第一个节点

		for (i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}

		//新节点的后继指向tmp的后继
		new->next = tmp->next;
		//tmp的后继指向new节点
		tmp->next = new;
	}


	return 0;
err0:
	return -1;
}

//链表的遍历
int slist_traverse(slist_t *s, op_t my_print)
{
	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == s || NULL == my_print)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 遍历链表
	tmp = s->p;  //指向链表的第一个节点
	while (NULL != tmp)
	{
		//调用用户自定义的函数输出数据
		my_print(tmp->data);

		//tmp指向下一个节点
		tmp = tmp->next;
	}

	return 0;
err0:
	return -1;
}

//删除链表节点（索引）
int slist_delete_by_index(slist_t *s, int index)
{
	int i = 0;
	node_t *tmp = NULL;
	node_t *del = NULL;

	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	if (index < 0 || index >= s->count)
	{
		printf("index 非法\n");
		goto err0;
	}

	//2. 删除节点

	if (0 == index)
	{
		del = s->p;
		s->p = del->next;
	}
	else
	{
		//找到要删除节点的上一个节点
		tmp = s->p;
		for (i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}

		//指向要删除的节点
		del = tmp->next;

		tmp->next = del->next;
	}

	//释放内存
	if (NULL != del->data)
	{
		free(del->data);
	}
	free(del);
	del = NULL;

	//3. 元素个数减1
	s->count--;

	return 0;
err0:
	return -1;
}

//删除链表节点（关键字)
int slist_delete_by_key(slist_t *s, void *key, cmp_t my_cmp)
{
	int i = 0;

	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == s || NULL == key || NULL == my_cmp)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 删除节点
	tmp = s->p;
	//通过关键字找到要删除节点的索引
	for (i = 0; i < s->count; i++)
	{
		if (my_cmp(tmp->data, key) == 0)
		{
			slist_delete_by_index(s, i);
			break;
		}

		tmp = tmp->next;
	}

	//3. 元素个数减1

	return 0;
err0:
	return -1;
}

//返回链表节点个数
int slist_count(slist_t *s)
{
	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 返回

	return s->count;
err0:
	return -1;
}

//链表的销毁
int slist_destroy(slist_t *s)
{
	node_t *tmp = NULL;

	node_t *save = NULL;

	//1. 参数检查
	if (NULL == s)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 循环删除节点空间
	tmp = s->p;
	while (NULL != tmp)
	{
		//保存下一个节点
		save = tmp->next;

		//释放数据内存空间
		if (NULL != tmp->data)
		{
			free(tmp->data);
			tmp->data = NULL;
		}

		//释放节点内存空间
		free(tmp);

		//tmp指向下一个节点
		tmp = save;
	}

	//3. 删除头信息结构体节点空间
	free(s);

	return 0;
err0:
	return -1;
}
