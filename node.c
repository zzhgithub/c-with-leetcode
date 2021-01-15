#include "node.h"
#include <stdlib.h>

struct TreeNode *createNode(int *a, int arraySize, int index);
// 二叉树初始化

/**
 * 输入一维数组 [1 2 3 4 5 6]
 *
 * 规律： 1
 *     2   3
 *    4 5 6 7
 */
struct TreeNode *init(int *a, int arraySize)
{
    return createNode(a, arraySize, 1);
}

/**
 * 递归创建节点
 */
struct TreeNode *createNode(int *a, int arraySize, int index)
{
    if (index > arraySize)
    {
        return NULL;
    }

    int val = a[index - 1];
    if (val == NULL)
    {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = createNode(a, arraySize, 2 * index);
    root->right = createNode(a, arraySize, 2 * index + 1);

    return root;
}
