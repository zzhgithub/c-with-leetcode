#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

int deep(struct TreeNode *root)
{
    int maxH = 0;

    if (root != NULL)
    {
        int r = deep(root->right);
        int l = deep(root->left);
        maxH = r > l ? r : l;
        return maxH + 1;
    }
    return maxH;
}

// 按照层遍历
// 反转索引
int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }

    int deepH = deep(root);
    *returnColumnSizes = (int *)malloc(sizeof(int) * deepH);
    int **ret = (int **)malloc(sizeof(int *) * deepH);
    int useIndex = 0;
    int lastIndex = 0;

    int len = 1;

    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * deepH * (deepH + 1));

    stack[lastIndex++] = root;

    while (len > 0)
    {
        (*returnColumnSizes)[*returnSize] = len;
        int offset = useIndex;
        ret[*returnSize] = (int *)malloc(sizeof(int) * len);
        int newLen = 0;
        for (int i = 0; i < len; i++)
        {
            struct TreeNode *temp;

            temp = stack[offset + len - 1 - i];

            useIndex++;
            ret[*returnSize][i] = temp->val;

            if ((*returnSize) % 2 == 0)
            {
                if (temp->left != NULL)
                {
                    stack[lastIndex++] = temp->left;
                    newLen++;
                }
                if (temp->right != NULL)
                {
                    stack[lastIndex++] = temp->right;
                    newLen++;
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    stack[lastIndex++] = temp->right;
                    newLen++;
                }
                if (temp->left != NULL)
                {
                    stack[lastIndex++] = temp->left;
                    newLen++;
                }
            }
        }

        len = newLen;
        (*returnSize)++;
    }

    return ret;
}

int main(void)
{
    int test[] = {3, 9, 20, INT16_MIN, INT16_MIN, 15, 7};
    struct TreeNode *root = init(test, LEN(test, int));

    int len, *columnSize;
    int **ret = zigzagLevelOrder(root, &len, &columnSize);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < columnSize[i]; j++)
        {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    // 最后可以遍历打印
}