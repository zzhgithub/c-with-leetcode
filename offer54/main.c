#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//二叉搜索树的第k大节点
struct LinkList
{
    int val;
    struct LinkList *next;
};

struct LinkList *createLink(int val)
{
    struct LinkList *ret = (struct LinkList *)malloc(sizeof(struct LinkList) * 1);
    ret->next = NULL;
    ret->val = val;
    return ret;
}

void addToList(struct LinkList *list, int val)
{
    // if (list->val == NULL)
    // {
    //     list->next = createLink(val);
    //     return;
    // }

    struct LinkList *pre = list;
    struct LinkList *head = list->next;

    while (head != NULL)
    {

        if (head->val > val)
        {
            printf("1\n");
            pre = head;
            head = head->next;
        }
        else
        {
            // 在head之前添加节点
            printf("3\n");
            struct LinkList *temp = createLink(val);
            pre->next = temp;
            temp->next = head;
            return;
        }
    }
    printf("2\n");
    pre->next = createLink(val);
}

struct LinkList *rr(struct TreeNode *root, struct LinkList *list)
{

    if (root == NULL)
    {
        return list;
    }
    addToList(list, root->val);
    rr(root->left, list);
    rr(root->right, list);

    return list;
}

int kthLargest(struct TreeNode *root, int k)
{
    // 思路 遍历二叉树 然后生成到有序是 数列中 最后通过值获取到值
    struct LinkList *temp = (struct LinkList *)malloc(sizeof(struct LinkList));
    temp->val = NULL;
    temp->next = NULL;
    struct LinkList *ret = rr(root, temp);
    if (ret == NULL)
    {
        return -1;
    }
    struct LinkList *head = ret;
    for (int i = 0; i < k; i++)
    {
        head = head->next;
    }
    return head->val;
}

/**
 * 注意上面的解法 非常不优雅 因为不知道 二叉搜索树中序遍历的 序列有序！
 */
int main(void)
{
    int test[] = {3, 1, 4, NULL, 2};
    struct TreeNode *root = init(test, sizeof(test) / sizeof(int));

    int ret = kthLargest(root, 1);
    printf("%d", ret);
}