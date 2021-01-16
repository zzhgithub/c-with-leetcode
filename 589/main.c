#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"
// N叉树的前序遍历

static int lastIndex = 0;

void addToLast(int *a, int val)
{
    a[lastIndex++] = val;
}

void rt(struct Node *root, int *a, int *returnSize)
{
    if (root == NULL)
    {
        return;
    }
    // printf("%d", root->val);
    if (a != NULL)
    {
        addToLast(a, root->val);
    }
    (*returnSize)++;
    if (root->numChildren == 0)
    {
        return;
    }

    for (int i = 0; i < root->numChildren; i++)
    {
        rt(root->children[i], a, returnSize);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorder(struct Node *root, int *returnSize)
{
    *returnSize = 0;
    lastIndex = 0;
    rt(root, NULL, returnSize);
    if (*returnSize > 0)
    {
        int *ret = (int *)malloc(sizeof(int) * (*returnSize));
        *returnSize = 0;
        rt(root, ret, returnSize);
        return ret;
    }

    return NULL;
}

int main(void)
{
    int size;
    struct Node *root = buildNode(1, 3);
    struct Node *node1 = buildNode(3, 2);
    struct Node *node2 = buildNode(2, 0);
    struct Node *node3 = buildNode(4, 0);

    root->children[0] = node1;
    root->children[1] = node2;
    root->children[2] = node3;

    struct Node *node4 = buildNode(5, 0);
    struct Node *node5 = buildNode(6, 0);

    node1->children[0] = node4;
    node1->children[1] = node5;

    int *a = preorder(root, &size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }

    free(a);
    return 0;
}