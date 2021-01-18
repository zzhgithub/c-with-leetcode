#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//invert-binary-tree
// 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。

struct TreeNode *invertTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode *temp;
    temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

int main(void)
{
    int test[] = {4, 2, 7, 1, 3, 6, 9};
    struct TreeNode *root = init(test, LEN(test, int));
    struct TreeNode *ret = invertTree(root);
    visiable(ret);
}