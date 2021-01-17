#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

bool _hasPathSum(struct TreeNode *root, int sum)
{
    if (root->right == NULL && root->left == NULL)
    {
        return sum == root->val;
    }

    return (root->left != NULL && _hasPathSum(root->left, sum - root->val)) ||
           (root->right != NULL && _hasPathSum(root->right, sum - root->val));
}

bool hasPathSum(struct TreeNode *root, int sum)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return sum == root->val;
    }

    return (root->left != NULL && _hasPathSum(root->left, sum - root->val)) ||
           (root->right != NULL && _hasPathSum(root->right, sum - root->val));
}

int main()
{
    int test[] = {1};
    struct TreeNode *root = init(test, LEN(test, int));
    if (hasPathSum(root, 1))
    {
        printf("1");
    }
    else
    {
        printf("2");
    }
}