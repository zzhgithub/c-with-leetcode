#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

// left <= current  && right > current
// max of left <= current && min of right > current

bool checkBST(struct TreeNode *root, long long max, long long min)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->val <= min || root->val >= max)
    {
        return false;
    }

    return checkBST(root->left, root->val, min) && checkBST(root->right, max, root->val);
}

bool isValidBST(struct TreeNode *root)
{
    return checkBST(root, LONG_MAX, LONG_MIN);
}

int main(void)
{
    int test[] = {};
    struct TreeNode *root = init(test, LEN(test, int));
}