#include "tree.h"

//前序遍历 根  左子树  右子树
int tree_pre_traverse(node_t *root)
{
	//递归结束条件
	if (NULL == root)
	{
		return 0;
	}

	//输出根节点数据
	printf("%c  ", root->ch);

	//前序遍历左子树
	tree_pre_traverse(root->lchild);

	//前序遍历右子树
	tree_pre_traverse(root->rchild);

	return 0;
}

//中序遍历 左子树 根 右子树
int tree_mid_traverse(node_t *root)
{
	//递归结束条件
	if (NULL == root)
	{
		return 0;
	}

	//中序遍历左子树
	tree_mid_traverse(root->lchild);

	//输出根节点数据
	printf("%c  ", root->ch);

	//中序遍历右子树
	tree_mid_traverse(root->rchild);

	return 0;
}

//后序遍历
int tree_post_traverse(node_t *root)
{
	//递归结束条件
	if (NULL == root)
	{
		return 0;
	}

	//后序遍历左子树
	tree_post_traverse(root->lchild);

	//后序遍历右子树
	tree_post_traverse(root->rchild);

	//输出根节点数据
	printf("%c  ", root->ch);

	return 0;
}

//统计二叉树中节点个数
int tree_count(node_t *root)
{
	if (NULL == root)
	{
		return 0;
	}

	//左子树节点数 + 右子树节点数 + 1
	return 1 + tree_count(root->lchild) + tree_count(root->rchild);
}


//统计二叉树中叶子节点个数  递归方式
int tree_leaf_count(node_t *root)
{
	int l = 0;
	int r = 0;

	if (NULL == root)
	{
		return 0;
	}

	//判断是否为叶子节点
	if ((NULL == root->lchild) && (NULL == root->rchild))
	{
		return 1;
	}

	//统计左子树叶子节点个数
	l = tree_leaf_count(root->lchild);

	//统计右子树节点个数
	r = tree_leaf_count(root->rchild);

	return l + r;
}

//统计二叉树中叶子节点个数  遍历的方式
int tree_leaf_count_v1(node_t *root, int *num)
{
	//为空 返回
	if (NULL == root)
	{
		return 0;
	}

	//叶子节点
	if ((NULL == root->lchild) && (NULL == root->rchild))
	{
		(*num)++;
		return 0;
	}

	//遍历左子树
	tree_leaf_count_v1(root->lchild, num);

	//遍历右子树
	tree_leaf_count_v1(root->rchild, num);

	return 0;
}

//计算二叉树的高度
int tree_depth(node_t *root)
{
	int l = 0;
	int r = 0;

	if (NULL == root)
	{
		return 0;
	}

	//计算左子树的高度
	l = tree_depth(root->lchild);

	//计算右子树的高度
	r = tree_depth(root->rchild);

	return 1 + (l > r ? l : r);
}

//二叉树的拷贝
node_t *tree_copy(node_t *root)
{
	node_t *new = NULL;
	node_t *lchild = NULL;
	node_t *rchild = NULL;

	if (NULL == root)
	{
		return NULL;
	}

	//递归拷贝左子树
	lchild = tree_copy(root->lchild);

	//递归拷贝右子树
	rchild = tree_copy(root->rchild);

	//分配根节点
	new = malloc(sizeof(node_t));
	if (NULL == new)
	{
		printf("malloc new 失败...\n");
		return NULL;
	}
	memset(new, 0, sizeof(node_t));

	//赋值
	new->ch = root->ch;
	new->lchild = lchild;
	new->rchild = rchild;

	return new;
}


//二叉树的销毁
int tree_destroy(node_t *root)
{
	if (NULL == root)
	{
		return 0;
	}

	//销毁左子树
	tree_destroy(root->lchild);

	//销毁右子树
	tree_destroy(root->rchild);

	printf("销毁节点 %c\n", root->ch);
	//销毁根节点
	free(root);


	return 0;
}




