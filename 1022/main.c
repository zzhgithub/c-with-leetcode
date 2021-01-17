#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//1022. 从根到叶的二进制数之和

void _fitData(struct TreeNode *root, int data, int *sum)
{
    if (root == NULL)
    {
        return;
    }

    int base = 2 * data + root->val;

    if (root->left == NULL && root->right == NULL)
    {
        //当前值为 添加到 sum 这是最后一个节点
        *sum = (*sum) + base;
        return;
    }
    _fitData(root->left, base, sum);
    _fitData(root->right, base, sum);
}

int sumRootToLeaf(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ret = 0;
    _fitData(root, 0, &ret);
    return ret;
}

int main(void)
{
    int test[] = {1, 0, 1, 0, 1, 0, 1};
    struct TreeNode *root = init(test, LEN(test, int));
    printf("%d\n", sumRootToLeaf(root));
}