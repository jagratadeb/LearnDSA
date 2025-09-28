#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *lchild, *rchild;
};

// Create a new node
struct Node *createNode(int key)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
}

// Insert into BST (recursive)
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (key < root->data)
        root->lchild = insert(root->lchild, key);
    else if (key > root->data)
        root->rchild = insert(root->rchild, key);
    return root;
}

// Preorder traversal
void preorder(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main()
{
    // Hardcoded array (not user input)
    int arr[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node *root = NULL;
    // Build BST from array
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);
    printf("Preorder traversal of BST: ");
    preorder(root);
    printf("\n");
    return 0;
}
