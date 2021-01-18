#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

#define MAX(x, y) x > y ? x : y

//maximum-depth-of-binary-tree

void _maxDepth(struct TreeNode *root, int deep, int *max)
{
    if (!root)
    {
        *max = MAX(*max, deep);
        return;
    }
    _maxDepth(root->left, deep + 1, max);
    _maxDepth(root->right, deep + 1, max);
}

int maxDepth(struct TreeNode *root)
{
    int max = 0;
    _maxDepth(root, 0, &max);
    return max;
}

int main(void)
{
    int test[] = {3, 9, 20, INT16_MIN, INT16_MIN, 15, 7};
    struct TreeNode *root = init(test, LEN(test, int));
    int ret = maxDepth(root);
    printf("max depth is {%d}\n", ret);
}