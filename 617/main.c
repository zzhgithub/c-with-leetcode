#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//617. 合并二叉树
struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return NULL;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 0;
    root->left = NULL;
    root->right = NULL;

    int t1Val = t1 ? t1->val : 0;
    int t2Val = t2 ? t2->val : 0;
    root->val = t1Val + t2Val;

    root->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    root->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);

    return root;
}

int main(void)
{
    int test1[] = {1, 3, 2, 5};
    int test2[] = {2, 1, 3, INT16_MIN, 4, INT16_MIN, 7};
    struct TreeNode *a, *b, *ret;
    a = init(test1, LEN(test1, int));
    b = init(test2, LEN(test2, int));
    ret = mergeTrees(a, b);
    visiable(ret);
}