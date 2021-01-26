
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

struct TreeNode *pruneTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left != NULL)
    {
        root->left = pruneTree(root->left);
    }

    if (root->right != NULL)
    {
        root->right = pruneTree(root->right);
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == 0)
        {
            return NULL;
        }
        else
        {
            return root;
        }
    }

    return root;
}

int main(void)
{
    int test[] = {1, INT16_MIN, 0, 0, 1};
    struct TreeNode *root = init(test, LEN(test, int));
    struct TreeNode *ret = pruneTree(root);
}