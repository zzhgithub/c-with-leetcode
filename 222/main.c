#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

int countNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main(void)
{
    int test[] = {1,2,3,4,5,6};
    struct TreeNode *root = init(test, LEN(test, int));
    int ret = countNodes(root);
    printf("%d\n", ret);
}