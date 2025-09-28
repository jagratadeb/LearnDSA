#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *root = NULL;

Node *createNode(int key)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    return t;
}

// Insert a node into BST (Recursive)
Node *insertRecursive(Node *p, int key)
{
    if (p == NULL)
    {
        Node *t = createNode(key);
        return t;
    }
    if (key < p->data)
        p->lchild = insertRecursive(p->lchild, key);
    else if (key > p->data)
        p->rchild = insertRecursive(p->rchild, key);
    // If key == p->data, do nothing (no duplicates)
    return p;
}

// Recursive BST search
Node *rSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    else if (key < p->data)
        return rSearch(p->lchild, key);
    else
        return rSearch(p->rchild, key);
}

// Iterative BST search
Node *iSearch(Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

// Find minimum value node in a BST (used for deletion)
Node *findMin(Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

// Recursive node deletion in BST
Node *deleteNode(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key < p->data)
        p->lchild = deleteNode(p->lchild, key);
    else if (key > p->data)
        p->rchild = deleteNode(p->rchild, key);
    else
    {
        // Node with only one child or no child
        if (p->lchild == NULL)
        {
            Node *temp = p->rchild;
            free(p);
            return temp;
        }
        else if (p->rchild == NULL)
        {
            Node *temp = p->lchild;
            free(p);
            return temp;
        }
        // Node with two children: Get inorder successor (smallest in right subtree)
        Node *temp = findMin(p->rchild);
        p->data = temp->data;
        p->rchild = deleteNode(p->rchild, temp->data);
    }
    return p;
}

int main()
{
    int keys[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++)
        root = insertRecursive(root, keys[i]);

    int choice, val;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert new node\n");
        printf("2. Display all nodes (Inorder)\n");
        printf("3. Search key\n");
        printf("4. Delete node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insertRecursive(root, val);
            printf("Inserted %d.\n", val);
        }
        else if (choice == 2)
        {
            printf("All nodes (Inorder): ");
            inorder(root);
            printf("\n");
        }
        else if (choice == 3)
        {
            printf("Enter key to search: ");
            scanf("%d", &val);
            Node *found = rSearch(root, val);
            if (found)
                printf("Recursive: Key %d found at address %p\n", val, (void *)found);
            else
                printf("Recursive: Key %d not found\n", val);
            found = iSearch(root, val);
            if (found)
                printf("Iterative: Key %d found at address %p\n", val, (void *)found);
            else
                printf("Iterative: Key %d not found\n", val);
        }
        else if (choice == 4)
        {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            printf("Deleted %d (if present).\n", val);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
