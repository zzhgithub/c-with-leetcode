#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../node.h"

#define MIN(x, y) x < y ? x : y

// 任意两个 节点差值 的最小值

// r (a){
//     index 0;

//     左边入 右边入 下一个 数据 变 index/2->left index/2->right
// }

// int getMinimumDifference(struct TreeNode *root)
// {
//     int ret = INT16_MAX;
//     struct TreeNode **array = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 1024);
//     //1 2 3 NULL 5 6
//     //0 1 2
//     //1x2 1x2 +1
//     //2x2 2x2 +1
//     // index/2 是 那个的root
//     // index%2 是 那个的
//     // 知道 index/2 这个节点是空的！
//     int index = 0;
//     array[index++] = root;
//     // 如果当前节点不是NULL 和array 所有的数进行减法后 进入数组
//     while (true)
//     {
//         int rootIndex = ((index + 1) / 2) - 1;
//         // 退出条件不正确！！
//         if (array[rootIndex] == NULL)
//         {
//             break;
//         }
//         struct TreeNode *temp;
//         if ((index + 1) % 2 == 0)
//         {
//             // 左节点
//             temp = array[rootIndex]->left;
//         }
//         else
//         {
//             // 右节点
//             temp = array[rootIndex]->right;
//         }
//         if (temp != NULL)
//         {
//             for (int i = 0; i < index; i++)
//             {
//                 if (array[i] != NULL)
//                 {
//                     ret = MIN(ret, abs(array[i]->val - temp->val));
//                 }
//             }
//         }
//         array[index] = temp;
//         index++;
//     }
//     return ret;
// }


void dfs(struct TreeNode* root, int* pre, int* ans) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, pre, ans);
    if (*pre == -1) {
        *pre = root->val;
    } else {
        *ans = fmin(*ans, root->val - (*pre));
        *pre = root->val;
    }
    dfs(root->right, pre, ans);
}

int getMinimumDifference(struct TreeNode* root) {
    int ans = INT32_MIN, pre = -1;
    dfs(root, &pre, &ans);
    return ans;
}

int main(void)
{
    int test[] = {236, 104, 701, INT32_MIN, 227, INT32_MIN, 911};
    struct TreeNode *root = init(test, LEN(test, int));
    int ret = getMinimumDifference(root);
    printf("%d", ret);
}