#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//树的节点类型
typedef struct _node_t {
    //数据域
    char ch;
    //左孩子指针域
    struct _node_t *lchild;
    //右孩子指针域
    struct _node_t *rchild;
}node_t;

//前序遍历
int tree_pre_traverse(node_t *root);
//中序遍历
int tree_mid_traverse(node_t *root);
//后序遍历
int tree_post_traverse(node_t *root);
//统计二叉树中节点个数
int tree_count(node_t *root);
//统计二叉树中叶子节点个数
int tree_leaf_count(node_t *root);
//统计二叉树中叶子节点个数
int tree_leaf_count_v1(node_t *root, int *num);
//计算二叉树的高度
int tree_depth(node_t *root);
//二叉树的拷贝
node_t *tree_copy(node_t *root);
//二叉树的销毁
int tree_destroy(node_t *root);
