#ifndef NODE_HEAD
#define NODE_HEAD

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *init(int *a, int arraySize);

void visiable(struct TreeNode *root);

#endif