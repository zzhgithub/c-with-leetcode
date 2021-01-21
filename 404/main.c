#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

// 左叶节点之和

// 重点在于怎么识别出右叶子节点

void _sumOfLeftLeaves(struct TreeNode *root, bool isLeft, int *sum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        _sumOfLeftLeaves(root->left, true, sum);
    }

    if (root->right != NULL)
    {
        _sumOfLeftLeaves(root->right, false, sum);
    }

    if (root->left == NULL && root->right == NULL && isLeft)
    {
        *sum += root->val;
        return;
    }
}

int sumOfLeftLeaves(struct TreeNode *root)
{
    int ret = 0;
    _sumOfLeftLeaves(root, false, &ret);
    return ret;
}

int main(void)
{
    int test[] = {3, 9, 20, INT16_MIN, INT16_MIN, 15, 7};
    struct TreeNode *root = init(test, LEN(test, int));
    int ret = sumOfLeftLeaves(root);
    printf("%d\n", ret);
}