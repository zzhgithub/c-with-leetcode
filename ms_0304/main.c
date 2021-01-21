#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../node.h"
#include "../listnode.h"

//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

void addToList(struct ListNode **list, int index, int val)
{
    if (list[index] == NULL)
    {
        list[index] = (struct ListNode *)malloc(sizeof(struct ListNode));
        list[index]->val = val;
        list[index]->next = NULL;
        return;
    }
    struct ListNode *head = list[index];
    while (head->next != NULL)
    {
        head = head->next;
    }
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    head->next = temp;
}

struct ListNode **listOfDepth(struct TreeNode *tree, int *returnSize)
{
    // 数据进度到队列里面
    // 数组内部的长度
    int len = 0;
    struct TreeNode **qeuen = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 1024);
    struct ListNode **ret = (struct ListNode **)malloc(sizeof(struct ListNode *) * 1024);
    *returnSize = 0;
    qeuen[len++] = tree;
    int index = 0;
    int lastIndex = 0;
    int firstIndex = 0;
    while (len > 0)
    {
        int newLen = 0;
        // quenu   fistindex  useIndex  len
        // 0       0          0         1
        // 0,2,3   1          2         2
        int less = firstIndex + len;
        for (int i = firstIndex; i < less; i++)
        {
            struct TreeNode *temp = qeuen[i];
            addToList(ret, index, temp->val);
            firstIndex++;
            if (temp->left != NULL)
            {
                newLen++;
                qeuen[++lastIndex] = temp->left;
            }
            if (temp->right != NULL)
            {
                newLen++;
                qeuen[++lastIndex] = temp->right;
            }
        }

        len = newLen;
        *returnSize = *returnSize + 1;
        index++;
    }

    return ret;
}

// int depth(struct TreeNode *tree)
// {
//     if (tree == NULL)
//     {
//         return 0;
//     }
//     int left = depth(tree->left);
//     int right = depth(tree->right);
//     return left > right ? (left + 1) : (right + 1);
// }

// struct ListNode **listOfDepth(struct TreeNode *tree, int *returnSize)
// {
//     *returnSize = 0;
//     if (tree == NULL)
//     {
//         return NULL;
//     }
//     /* 层序遍历 队列 */
//     /* 先计算深度 */
//     int dep = depth(tree);
//     struct ListNode **ret = (struct ListNode **)malloc(sizeof(struct ListNode *) * dep);

//     int max_size = pow(2, dep - 1);
//     struct TreeNode *queue[max_size * dep];
//     queue[0] = tree;
//     int start = 0; /* 队首 指向第一个元素 */
//     int end = 1;   /* 队尾 指向最后一个元素的下一个 */

//     while (end > start)
//     { /* 队列不为空就有值 */
//         int old_start = start;
//         int old_end = end;
//         start = end; /* 更新队列 */
//         /* 先把当前层入队，再把上一次出队 */
//         for (int i = old_start; i < old_end; i++)
//         {
//             if (queue[i] == NULL)
//             {
//                 continue;
//             }
//             if (queue[i]->left != NULL)
//             {
//                 queue[end++] = queue[i]->left;
//             }
//             if (queue[i]->right != NULL)
//             {
//                 queue[end++] = queue[i]->right;
//             }
//         }
//         ret[*returnSize] = (struct ListNode *)malloc(sizeof(struct ListNode)); /* head */
//         struct ListNode *head = ret[*returnSize];
//         head->val = queue[old_start]->val;
//         head->next = NULL;
//         for (int i = old_start + 1; i < old_end; i++)
//         {
//             struct ListNode *current = (struct ListNode *)malloc(sizeof(struct ListNode));
//             current->val = queue[i]->val;
//             current->next = NULL;
//             head->next = current;
//             head = head->next;
//         }
//         (*returnSize)++;
//     }

//     return ret;
// }
// 上面的解法错了吗？？ 我本地执行可以的

int main(void)
{
    int test[] = {1, 2, 3, 4, 5, INT16_MIN, 7, 8};
    struct TreeNode *root = init(test, LEN(test, int));
    int depth;
    struct ListNode **ret = listOfDepth(root, &depth);
    for (int i = 0; i < depth; i++)
    {
        struct ListNode *temp = ret[i];
        while (temp != NULL)
        {
            printf("%d,", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }

    free(ret);
}