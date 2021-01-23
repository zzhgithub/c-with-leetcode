#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

struct TreeNode *insertIntoMaxTree(struct TreeNode *root, int val)
{

    if (root == NULL)
    {
        struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (val > root->val)
    {
        struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = root;
        temp->right = NULL;
        return temp;
    }
    else
    {
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
}

int main(void)
{
    int test[] = {4, 1, 3, INT16_MIN, INT16_MIN, 2}, add = 5;
    struct TreeNode *root = init(test, LEN(test, int));
    struct TreeNode *ret = insertIntoMaxTree(root, add);
}