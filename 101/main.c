#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//symmetric-tree

bool isSymmetric(struct TreeNode *root)
{
    return true;
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