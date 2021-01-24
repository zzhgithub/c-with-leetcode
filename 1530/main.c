#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"
#include <memory.h>



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_LEN 2000
#define MAX_LEAF_NUM 600
typedef struct {
    short distanceToLeaf[MAX_LEAF_NUM];
    short offset;
}VECTOR;

// 模拟一下vector，使用全局变量
static VECTOR g_memmanage[MAX_LEN] = {0};
static int g_memLen = 0;
static void InitMem(void)
{
    memset(g_memmanage, 0, sizeof(g_memmanage));
    g_memLen = 0;
}

static VECTOR *CreateMem(void)
{
    return &g_memmanage[g_memLen++];
}

// 这里是主要处理函数
int g_ret = 0;

VECTOR* Dfs(struct TreeNode *root, int distance)
{
    VECTOR *res = CreateMem();
    if (root->left == NULL && root->right == NULL) {
        res->offset = 1;
        return res;
    }

    VECTOR *left = NULL;
    if (root->left != NULL) {
        left = Dfs(root->left, distance);

        for (int i = 0; i < left->offset; i++) {
            res->distanceToLeaf[i] = left->distanceToLeaf[i] + 1;
        }
        res->offset += left->offset;
    }

    VECTOR *right = NULL;
    if (root->right != NULL) {
        right = Dfs(root->right, distance);

        int tmpOffset = res->offset;
        for (int i = 0; i < right->offset; i++) {
            res->distanceToLeaf[i + tmpOffset] = right->distanceToLeaf[i] + 1;
        }
        res->offset += right->offset;
    }

    if (left != NULL && right != NULL) {
        for (int i = 0; i < left->offset; i++) {
            for (int j = 0; j < right->offset; j++) {
                if (left->distanceToLeaf[i] + right->distanceToLeaf[j] + 2 <= distance) {
                    g_ret++;
                }
            }
        }
    }
    return res;
}

int countPairs(struct TreeNode* root, int distance){
    g_ret = 0;
    if (root == NULL) {
        return 0;
    }
    InitMem();
    Dfs(root, distance);
    return g_ret;
}

int main(void)
{
    int test[] = {};
}