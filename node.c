#include "node.h"
#include <stdlib.h>
#include <stdio.h>

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
    // printf("%d,%d\n", arraySize, index);
    if (index > arraySize)
    {
        return NULL;
    }

    int val = a[index - 1];
    if (val <= INT16_MIN)
    {
        // printf("%d\n", val);
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = createNode(a, arraySize, 2 * index);
    root->right = createNode(a, arraySize, 2 * index + 1);

    return root;
}

void handleVal(int val)
{
    printf("Node is %d\n", val);
}

void r(struct TreeNode *root, void (*handle)(int))
{
    if (root == NULL)
    {
        printf("Null Node;\n");
        return;
    }
    handle(root->val);
    r(root->left, handle);
    r(root->right, handle);
}

void visiable(struct TreeNode *root)
{
    // todo 打印成 一种更加优美的方式
    //    比如:
    //     1
    //    /  \
    //   2    2
    //  / \  / \
    // 33  1 2  3
    // 自己给自己的难题 一种排版算法！
    r(root, handleVal);
}

/**
 * 初始化 后面一个标识子 node 个数 然后
 * todo??
 */
struct Node *initNode(int *a, int arraySize)
{
    return NULL;
}

struct Node *buildNode(int val, int numChildern)
{
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->val = val;
    root->numChildren = numChildern;

    if (numChildern == 0)
    {
        root->children = NULL;
    }
    else
    {
        struct Node **childern = (struct Node **)malloc(sizeof(struct Node *) * numChildern);
        root->children = childern;
    }

    return root;
}