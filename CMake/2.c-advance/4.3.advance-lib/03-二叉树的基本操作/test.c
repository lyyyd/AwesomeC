#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"


int main()
{
    int num = 0;

    node_t *nroot = NULL;

    node_t nodeA = { 'A', NULL, NULL };
    node_t nodeB = { 'B', NULL, NULL };
    node_t nodeC = { 'C', NULL, NULL };
    node_t nodeD = { 'D', NULL, NULL };
    node_t nodeE = { 'E', NULL, NULL };
    node_t nodeF = { 'F', NULL, NULL };
    node_t nodeH = { 'H', NULL, NULL };
    node_t nodeG = { 'G', NULL, NULL };

    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeF;

    nodeB.rchild = &nodeC;

    nodeC.lchild = &nodeD;
    nodeC.rchild = &nodeE;

    nodeF.rchild = &nodeG;

    nodeG.lchild = &nodeH;

    printf("前序遍历： ");
    tree_pre_traverse(&nodeA);
    printf("\n");

    printf("中序遍历： ");
    tree_mid_traverse(&nodeA);
    printf("\n");

    printf("后序遍历： ");
    tree_post_traverse(&nodeA);
    printf("\n");

    printf("二叉树中节点数： %d\n", tree_count(&nodeA));
    printf("二叉树中叶子节点数： %d\n", tree_leaf_count(&nodeA));
    tree_leaf_count_v1(&nodeA, &num);
    printf("二叉树中叶子节点数： %d\n", num);

    printf("二叉树深度：%d\n", tree_depth(&nodeA));

    //拷贝二叉树
    nroot = tree_copy(&nodeA);
    printf("前序遍历： ");
    tree_pre_traverse(nroot);
    printf("\n");


    tree_destroy(nroot);

    system("pause");
    return 0;
}
