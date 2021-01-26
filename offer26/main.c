#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

// B 是不是在 A中

bool isSubStructureForHead(struct TreeNode *A, struct TreeNode *B)
{
    if (A == NULL && B == NULL)
    {
        return true;
    }

    if (A == NULL || B == NULL)
    {
        return false;
    }

    if (A->val == B->val)
    {
        bool ret = true;
        if (B->right != NULL)
        {
            ret = ret && isSubStructureForHead(A->right, B->right);
        }
        if (B->left != NULL)
        {
            ret = ret && isSubStructureForHead(A->left, B->left);
        }
        return ret;
    }
    else
    {
        return false;
    }
}

bool isSubStructure(struct TreeNode *A, struct TreeNode *B)
{
    if (A == NULL && B == NULL)
    {
        return true;
    }

    if (A == NULL || B == NULL)
    {
        return false;
    }

    if (isSubStructureForHead(A, B))
    {
        return true;
    }
    else
    {
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
}

int main(void)
{
    int test[] = {3, 4, 5, 1, 2};
    int test2[] = {4, 1};

    struct TreeNode *root = init(test, LEN(test, int));
    struct TreeNode *root2 = init(test2, LEN(test2, int));

    if (isSubStructure(root, root2))
    {
        printf("T");
    }
    else
    {
        printf("Nil");
    }
}