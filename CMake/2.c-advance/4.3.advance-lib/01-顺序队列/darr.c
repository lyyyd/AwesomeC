#include "darr.h"

//动态数组初始化
darr_t *darr_init(int capacity)
{

	darr_t *d = NULL;

	//参数非法检查
	if (capacity <= 0)
	{
		printf("The parameter is invalid\n");
		goto err0;
	}

	//分配空间 alloc
	d = malloc(sizeof(darr_t));
	if (NULL == d)
	{
		printf("malloc darr_t failed...\n");
		goto err0;
	}
	memset(d, 0, sizeof(darr_t));

	//分配空间
	d->data = malloc(capacity * sizeof(void *));
	if (NULL == d->data)
	{
		printf("malloc data failed..\n");
		goto err0;
	}
	//清零
	memset(d->data, 0, capacity * sizeof(void *));

	//初始化 元素的个数
	d->count = 0;

	//容量 存储元素最大数量
	d->capacity = capacity;


	return d;

err0:
	if (NULL != d)
	{
		free(d);
	}
	return NULL;
}

//动态数组插入数据
int darr_insert_by_index(darr_t *d, int index, void *data)
{
	int i = 0;

	void **new_data = NULL;
	int new_cap = 0;

	//参数检查
	if (NULL == d || NULL == data)
	{
		printf("some parameters are NULL\n");
		goto err0;
	}


	//下标非法 直接尾部插入数据
	if (index < 0 || index > d->count)
	{
		index = d->count;
	}

	//判断容量是否不够
	if (d->count >= d->capacity)
	{
		new_cap = d->capacity * 2;

		//分配空间 realloc
		new_data = malloc(new_cap * sizeof(void *));
		if (NULL == new_data)
		{
			printf("malloc new_data failed...\n");
			goto err0;
		}
		memset(new_data, 0, new_cap * sizeof(void*));

		//拷贝数据
		memcpy(new_data, d->data, d->count * sizeof(void*));

		//释放内存
		if (NULL != d->data)
		{
			free(d->data);
		}

		d->data = new_data;

		d->capacity = new_cap;

	}

	//插入数据  memmove
	for (i = d->count - 1; i >= index; i--)
	{
		d->data[i + 1] = d->data[i];
	}

	d->data[index] = data;

	//元素个数自增
	d->count++;

	return 0;
err0:
	return -1;
}

//动态数组删除 通过索引
int darr_delete_by_index(darr_t *d, int index)
{
	int i = 0;

	//1. 参数检查
	if (NULL == d)
	{
		printf("the d is NULL\n");
		goto err0;
	}

	if (index < 0 || index >= d->count)
	{
		printf("无效的索引\n");
		goto err0;
	}

	//2. 移动元素的位置 memmove
	for (i = index; i < d->count - 1; i++)
	{
		d->data[i] = d->data[i + 1];
	}

	//将数组中最后一个元素设置为NULL
	d->data[d->count - 1] = NULL;

	//3. 元素个数自减
	d->count--;

	return 0;
err0:
	return -1;
}

//动态数组删除 通过关键字(通过姓名）
int darr_delete_by_key(darr_t *d, void *key, cmp_t my_cmp)
{
	int i = 0;

	//1. 参数检查
	if (NULL == d || NULL == key || NULL == my_cmp)
	{
		printf("Some parameter are NULL\n");
		goto err0;
	}

	//2. 删除符合条件的数据
	for (i = 0; i < d->count; i++)
	{
		if (my_cmp(d->data[i], key) == 0)
		{
			darr_delete_by_index(d, i);
			break;
		}
	}

	//3. 元素个数自减


	return 0;
err0:
	return -1;
}

//动态数组遍历
int darr_traverse(darr_t *d, op_t my_print)
{
	int i = 0;

	//参数检查
	if (NULL == d || NULL == my_print)
	{
		printf("some parameters are NULL\n");
		goto err0;
	}

	//遍历动态数组
	for (i = 0; i < d->count; i++)
	{
		//回调函数
		my_print(d->data[i]);
	}

	return 0;
err0:
	return -1;
}

//动态数组销毁
int darr_destroy(darr_t *d)
{
	//参数非法检查
	if (NULL == d)
	{
		printf("The parameter is invalid\n");
		goto err0;
	}

	//释放data
	if (NULL != d->data)
	{
		free(d->data);
		d->data = NULL;
	}

	//释放d
	free(d);
	d = NULL;

	return 0;
err0:
	return -1;
}
