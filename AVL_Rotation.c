
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n) // this is node pointer
{
    if (n == NULL)
        return 0;
    return n->height;
}

// Dynemic memory allocate
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    // NEW node = leaf node
    return node;
}

int max (int a, int b){
    return a>b?a:b;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return (createNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // BF = Balance Factor
    int bf = getBalanceFactor(node);

    // left left case LL
    if (bf > 1 && key < node->left->key)
    {
        rightRotate(node);
    }

    // right right case  RR
    if (bf < -1 && key > node->right->key)
    {
        leftRotate(node);
    }

    // left right  case  LR
    if (bf>1  && key > node->right->key)
    {
        node->left = leftRotate (node->left);
        rightRotate(node);
    }

    // right left case   RL
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        leftRotate(node);
    }
    return node;
}


int main (){
  return 0;   
}
















