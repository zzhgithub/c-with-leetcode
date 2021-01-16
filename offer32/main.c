#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

// 从上到下打印二叉树
// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

struct LinkList
{
    int val;
    struct LinkList *next;
};

struct List
{
    struct LinkList *data;
    struct List *next;
};

struct List *createLink()
{
    struct List *ret = (struct List *)malloc(sizeof(struct List));
    ret->data = NULL;
    ret->next = NULL;
    return ret;
}

struct LinkList *createLinkList(int val)
{
    struct LinkList *ret = (struct LinkList *)malloc(sizeof(struct LinkList));
    ret->next = NULL;
    ret->val = val;
    printf("added val is %d\n", ret->val);
    return ret;
}

// 获取长度
int sizeOfList(struct List *list)
{
    if (list == NULL || list->data == NULL)
    {
        return 0;
    }
    int ret = 1;
    struct List *head = list;
    while (head->next != NULL)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

int sizeOfLinkList(struct LinkList *list)
{
    if (list == NULL)
    {
        return 0;
    }
    int ret = 1;
    struct LinkList *head = list;
    while (head->next != NULL)
    {
        ret++;
        head = head->next;
    }

    return ret;
}

int *sizeColumOfList(struct List *list)
{
    int len = sizeOfList(list);
    int *ret = (int *)malloc(sizeof(int) * len);
    struct List *head = list;
    for (int i = 0; i < len; i++)
    {
        ret[i] = sizeOfLinkList(head->data);
        head = head->next;
    }
    return ret;
}

int *linkListToArray(struct LinkList *list)
{
    int size = sizeOfLinkList(list);
    if (size == 0)
    {
        return NULL;
    }
    int *ret = (int *)malloc(sizeof(int) * size);
    struct LinkList *head = list;
    for (int i = 0; i < size; i++)
    {
        printf("value in linkList is %d\n", head->val);
        ret[i] = head->val;
        head = head->next;
    }
    return ret;
}

void addToList(struct LinkList *list, int val)
{
    struct LinkList *head = list;
    for (;;)
    {
        printf("old val is %d\n", head->val);
        if (head->next == NULL)
        {
            head->next = createLinkList(val);
            return;
        }
        head = head->next;
    }
}

int **listToArray(struct List *list)
{
    int size = sizeOfList(list);
    if (size == 0)
    {
        return NULL;
    }

    int **ret = (int **)malloc(sizeof(int *) * size);
    struct List *head = list;
    for (int i = 0; i < size; i++)
    {
        // 这里竟然没有报错
        ret[i] = linkListToArray(head->data);
        head = head->next;
    }

    return ret;
}

void addIntoList(struct List *list, int val, int deep)
{
    printf("add val is %d", val);
    struct List *current = list;
    for (int i = 0; i < deep; i++)
    {
        if (current->next == NULL)
        {
            current->next = createLink();
        }
        current = current->next;
    }

    if (current->data == NULL)
    {
        current->data = createLinkList(val);
    }
    else
    {
        addToList(current->data, val);
    }
}

void visit(struct TreeNode *root, struct TreeNode *list, int deep)
{
    if (root == NULL)
    {
        printf("last Node!\n");
        return;
    }
    // 存入到数据中
    addIntoList(list, root->val, deep);
    // 先左边
    visit(root->left, list, deep + 1);
    // 再右边
    visit(root->right, list, deep + 1);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **
levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    // 创建总数据
    struct List *list = createLink();
    visit(root, list, 0);
    printf("visit all\n");
    int len = sizeOfList(list);
    printf("len is %d\n", len);
    *returnSize = len;
    *returnColumnSizes = sizeColumOfList(list);
    for (int i = 0; i < len; i++)
    {
        printf("col is %d\n", (*returnColumnSizes)[i]);
    }
    return listToArray(list);
}

int main(void)
{
    int returnSize, *retrunColumnSize;
    int test[] = {3, 9, 20, NULL, NULL, 15, 7};
    struct TreeNode *root = init(test, sizeof(test) / sizeof(int));
    visiable(root);
    printf("tree init\n");
    int **ret = levelOrder(root, &returnSize, &retrunColumnSize);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < retrunColumnSize[i]; j++)
        {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
}