#include "slist.h"


//初始化
slist_t *slist_init(op_t my_destroy)
{
	slist_t *s = NULL;

	//1. 分配空间
	s = malloc(sizeof(slist_t));
	if (NULL == s)
	{
		printf("分配空间失败...\n");
		goto err0;
	}
	memset(s, 0, sizeof(slist_t));

	//2. 初始化

	//s->p指向链表的第一个节点  此时链表为空
	s->p = NULL;

	//链表中节点个数
	s->count = 0;

	//初始化自定义销毁函数
	s->my_destroy = my_destroy;

	return s;
err0:
	return NULL;
}

//插入
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

	//如果index非法  直接尾插
	if (index < 0 || index > s->count)
	{
		index = s->count;
	}

	new = data;

	//2. 插入节点
	if (0 == index)
	{
		new->next = s->p;
		s->p = new;
	}
	else
	{
		tmp = s->p;
		//找到插入位置前一个节点
		for (i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}

		//新节点的后继为tmp节点后继
		new->next = tmp->next;

		//tmp的后继为new
		tmp->next = new;
	}

	//3. 个数加1
	s->count++;

	return 0;
err0:
	return -1;
}

//删除(index)
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

	//2. 找到要删除节点前一个节点
	tmp = s->p;
	if (0 == index)
	{
		del = tmp;
		s->p = tmp->next;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}

		//要删除节点
		del = tmp->next;

		tmp->next = del->next;
	}


	//释放空间 --->
	s->my_destroy(del);

	//3. count减1
	s->count--;

	return 0;
err0:
	return -1;
}

//遍历
int slist_traverse(slist_t *s, op_t my_print)
{
	node_t *tmp = NULL;

	//1. 参数检查
	if (NULL == s || NULL == my_print)
	{
		printf("参数非法\n");
		goto err0;
	}

	//2. 遍历
	//指向链表的第一个节点
	tmp = s->p;
	while (NULL != tmp)
	{
		my_print(tmp);
		tmp = tmp->next;
	}

	return 0;
err0:
	return -1;
}

//销毁
int slist_destroy(slist_t *s)
{
	node_t *tmp = NULL;
	node_t *save = NULL;

	tmp = s->p;
	while (NULL != tmp)
	{
		//保存下一个节点
		save = tmp->next;
		if (NULL != s->my_destroy)
		{
			s->my_destroy(tmp);
		}

		tmp = save;
	}

	free(s);

	return 0;
}