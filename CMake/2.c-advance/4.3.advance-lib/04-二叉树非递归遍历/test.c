#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"

//节点类型
typedef struct _tree_node_t {
    char ch;
    struct _tree_tree_node_t *lchild;
    struct _tree_node_t *rchild;
    int flag;
}tree_node_t;

//非递归前序遍历二叉树
int tree_pre_traverse(tree_node_t* root)
{
    stack_t *s = NULL;

    tree_node_t node;

    //参数检查
    if (NULL == root)
    {
        printf("root为空\n");
        return -1;
    }

    //初始化一个栈
    s = stack_init(sizeof(tree_node_t), NULL);

    //根节点进栈
    stack_push(s, root);

    //判断栈是否为空
    while (stack_is_empty(s))
    {
        //清零
        memset(&node, 0, sizeof node);

        //出栈
        stack_pop(s, &node);

        if (node.flag == 1)
        {
            printf("%c ", node.ch);
            continue;
        }

        node.flag = 1;

        //右子树进栈
        if (NULL != node.rchild)
        {
            stack_push(s, node.rchild);
        }
        //左子树进栈
        if (NULL != node.lchild)
        {
            stack_push(s, node.lchild);
        }

        //根节点进栈
        stack_push(s, &node);
    }

    return 0;
}

int main()
{
    int num = 0;

    tree_node_t *nroot = NULL;

    tree_node_t nodeA = { 'A', NULL, NULL, 0 };
    tree_node_t nodeB = { 'B', NULL, NULL, 0 };
    tree_node_t nodeC = { 'C', NULL, NULL, 0 };
    tree_node_t nodeD = { 'D', NULL, NULL, 0 };
    tree_node_t nodeE = { 'E', NULL, NULL, 0 };
    tree_node_t nodeF = { 'F', NULL, NULL, 0 };
    tree_node_t nodeH = { 'H', NULL, NULL, 0 };
    tree_node_t nodeG = { 'G', NULL, NULL, 0 };

    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeF;

    nodeB.rchild = &nodeC;

    nodeC.lchild = &nodeD;
    nodeC.rchild = &nodeE;

    nodeF.rchild = &nodeG;

    nodeG.lchild = &nodeH;

    printf("前序遍历: ");
    tree_pre_traverse(&nodeA);
    printf("\n");

    system("pause");
    return 0;
}
