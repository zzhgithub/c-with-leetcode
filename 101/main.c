#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//symmetric-tree

bool isEquale(struct TreeNode *left, struct TreeNode *right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    if (left != NULL && right != NULL)
    {
        // 进一步判断一下 左右的结果
        if (left->val != right->val)
        {
            return false;
        }
        return isEquale(left->left, right->right) && isEquale(left->right, right->left);
    }
    else
    {
        return false;
    }
}

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    return isEquale(root->left, root->right);
}

void main()
{
    //初始化测试数据
    int test[] = {1, 2, 2, 3, 4, 4, 3};
    struct Node *tree;
    tree = init(test, sizeof(test) / sizeof(int));

    if (isSymmetric(tree))
    {
        printf("true");
    }
    else
    {
        printf("fasle");
    }
    return;
}