#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../node.h"

//606. 根据二叉树创建字符串

#define MAXSIZE 32768
void toStr(struct TreeNode *t, char *re)
{
    char temp[10];
    if (t)
    {
        sprintf(temp, "%d", t->val);
        strcat(re, temp);
        if (t->left || t->right)
        {
            strcat(re, "(");
            toStr(t->left, re);
            strcat(re, ")");
        }
        if (t->right)
        {
            strcat(re, "(");
            toStr(t->right, re);
            strcat(re, ")");
        }
    }
}
char *tree2str(struct TreeNode *t)
{
    // 注意在 使用strcat 时 前要申请足够的内存空间
    char *re = (char *)calloc(MAXSIZE, sizeof(char));
    toStr(t, re);
    return re;
}

int main(void)
{
    int test[] = {1, 2, 3, 4};
    struct TreeNode *root = init(test, LEN(test, int));
    char *ret = tree2str(root);
    printf("%s", ret);
}