#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct Node *root)
{
    // left->right->root
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
// this is use for searching for element 
struct Node *search(struct Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main()
{

    struct Node *p = createNode(7);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(11);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(6);
    /* the binarey search tree are left nood is lesser
    and right nood is greater
    In order traversal of BST gives an asanding sorted array*/

    // this is binary search tree
    //        7
    //       / \
    //      5   11
    //     / \
    //    1   6

    // Linking the root node with left and right cildren
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    struct Node* n = search(p, 11);
    if(n!=NULL){
        printf("Found: %d", n->data);
    }
    else{
        printf("Element not Found");
    }

    // 1 = true
    // 0 = false

    return 0;
}