#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    // todo
    // 如果 root == p 获取 root == q 那么剩下的节点肯定 在root 上
    // root 的值  如果 p 和 q 都 大于 或者 都小于 中间这个节点 那么要 根据大小 向下找
    // 如果  一个 大于 一个 小于 也在这个几点上

    int rootVal, pVal, qVal;
    rootVal = root->val;
    pVal = p->val;
    qVal = q->val;

    if ((rootVal - pVal) * (rootVal - qVal) <= 0)
    {
        return root;
    }

    if (rootVal - pVal > 0)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else
    {
        return lowestCommonAncestor(root->right, p, q);
    }
}

int main(void)
{
    int test[] = {6, 2, 8, 0, 4, 7, 9, INT16_MIN, INT16_MIN, 3, 5};
    struct TreeNode *root = init(test, LEN(test, int));
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->val = 2;
    q->val = 8;

    struct TreeNode *ret = lowestCommonAncestor(root, p, q);
    printf("%d", ret->val);
}
