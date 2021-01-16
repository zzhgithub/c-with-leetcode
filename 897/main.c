#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

// 给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

// 注意是重新排列 而不是 新建！！！

// 中序遍历 + 直接构造！

// 中序遍历
// left=NULL
// 当我们遍历到一个节点时，把它的左孩子设为空，并将其本身作为上一个遍历到的节点的右孩子

struct TreeNode *_increasingBST(struct TreeNode *root, struct TreeNode *pre)
{
    if (root == NULL)
    {
        return pre;
    }
    // 为什么是中序的
    // 因为先遍历了 left 之后是本身这个节点
    struct TreeNode *temp = _increasingBST(root->left, root);
    root->left = NULL;
    root->right = _increasingBST(root->right, pre);
    return temp;
}

struct TreeNode *increasingBST(struct TreeNode *root)
{
    return _increasingBST(root, NULL);
}

int main(void)
{
    int test[] = {5, 3, 6, 2, 4, NULL, 8, 1, NULL, NULL, NULL, 7, 9};
    struct TreeNode *root = init(test, sizeof(test) / sizeof(int));
    visiable(increasingBST(root));
}