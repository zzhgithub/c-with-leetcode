#ifndef NODE_HEAD
#define NODE_HEAD
#define LEN(x, y) (sizeof(x) / sizeof(y))
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *init(int *a, int arraySize);

void visiable(struct TreeNode *root);

struct Node
{
    int val;
    int numChildren;
    struct Node **children;
};

/**
 * 初始化
 */
struct Node *initNode(int *a, int arraySize);

/**
 * 初始化一个节点
 */
struct Node *buildNode(int val, int numChildern);

#endif