#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Node structure for AVL Tree
struct Node
{
    struct Node *lchild; // Pointer to left child
    int data;            // Value stored in node
    int height;          // Height of the node
    struct Node *rchild; // Pointer to right child
} *root = NULL;

// Calculate height of a node
int nodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0; // Height of left child
    hr = p && p->rchild ? p->rchild->height : 0; // Height of right child
    return (hl > hr) ? hl + 1 : hr + 1;          // Height is max of left/right + 1
}

// Calculate balance factor of a node
int balanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr; // Difference in heights
}

// LL Rotation: Single right rotation
struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    // Update heights
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    // Update root if needed
    if (root == p)
        root = pl;
    return pl;
}

// RR Rotation: Single left rotation
struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    // Update heights
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    if (root == p)
        root = pr;
    return pr;
}

// LR Rotation: Left-Right double rotation
struct Node *LRRotation(struct Node *p)
{
    p->lchild = RRRotation(p->lchild); // First right rotate left child
    return LLRotation(p);              // Then left rotate node
}

// RL Rotation: Right-Left double rotation
struct Node *RLRotation(struct Node *p)
{
    p->rchild = LLRotation(p->rchild); // First left rotate right child
    return RRRotation(p);              // Then right rotate node
}

// Forward declarations for rotation functions (needed for RInsert)
// struct Node *LLRotation(struct Node *p);
// struct Node *RRRotation(struct Node *p);
// struct Node *LRRotation(struct Node *p);
// struct Node *RLRotation(struct Node *p);

// Recursive insert for AVL tree
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    // If tree/subtree is empty, create new node
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; // New node is a leaf
        t->lchild = t->rchild = NULL;
        return t;
    }
    // Insert in left or right subtree
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    // Update height after insertion
    p->height = nodeHeight(p);
    // Check balance and perform rotations if needed
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p); // Left-Left case
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p); // Left-Right case
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRRotation(p); // Right-Right case
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLRotation(p); // Right-Left case
    return p;                 // No rotation needed
}

// Inorder traversal: prints nodes in sorted order
void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

// Preorder traversal: prints root, then left, then right
void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    // Example array to build AVL tree (no user input)
    int arr[] = {10, 5, 2, 8, 15, 12, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = NULL;
    // Insert each element into AVL tree
    for (int i = 0; i < n; i++)
        root = RInsert(root, arr[i]);
    // Display traversals
    printf("Inorder traversal of AVL tree: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal of AVL tree: ");
    preorder(root);
    printf("\n");
    return 0;
}