#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

#define Max(x, y) x > y ? x : y

//balanced-binary-tree

// void r(struct TreeNode *root)
// {
//     r(root->left);
//     r(root->right);
// }

int heigh(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("last Node");
        return 0;
    }
    printf("%d", root->val);
    int left, right;
    left = heigh(root->left) + 1;
    right = heigh(root->right) + 1;

    return left > right ? left : right;
}

/**
 * 检查是否平衡并且返回 层数
 *
 */
int isSimpleBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left, right;
    // 左节点平衡 右节点平衡
    left = isSimpleBalanced(root->left);
    // 两边的差值不超过 1
    right = isSimpleBalanced(root->right);

    if (left == -1 || right == -1)
    {
        return -1;
    }
    if ((left - right) > 1 || (left - right) < -1)
    {
        return -1;
    }
    printf("left is %d\n right is %d\n", left, right);
    return (Max(left, right)) + 1;
}

bool isBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int hight = isSimpleBalanced(root);
    printf("hight = %d\n", hight);
    return hight > 0;
}

void main()
{
    // int test[] = {3, 9, 20, NULL, NULL, 15, 7};
    // int test[] = {1, 2, 2, 3, 3, NULL, NULL, 4, 4};
    int test[] = {1, 2};
    struct Node *tree;
    tree = init(test, sizeof(test) / sizeof(int));
    printf("tree init\n");
    // visiable(tree);
    if (isBalanced(tree))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}