#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

// 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
// 二叉树的根是数组 nums 中的最大元素。
// 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
// 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
// 返回有给定数组 nums 构建的 最大二叉树 。

// 找到最大值的索引
int findMax(int *nums, int numsSize)
{
    int max = nums[0];
    int ret = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            ret = i;
        }
    }
    return ret;
}

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
    if (numsSize == 0)
    {
        return NULL;
    }
    // 找到最大值的索引
    int maxIndex = findMax(nums, numsSize);
    // 创建主节点
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[maxIndex];

    root->left = constructMaximumBinaryTree(nums, maxIndex);
    if (maxIndex < numsSize - 1)
    {
        root->right = constructMaximumBinaryTree(&(nums[maxIndex + 1]), numsSize - 1 - maxIndex);
    }
    else
    {
        root->right = NULL;
    }
    return root;
}

int main(void)
{
    int test[] = {3, 2, 1, 6, 0, 5};
    struct TreeNode *ret = constructMaximumBinaryTree(test, LEN(test, int));
    visiable(ret);
}