
#include <stdio.h>
#include <stdlib.h>

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

// Insert a node into BST (iterative)
void insert(int key)
{
    Node *t = root, *r = NULL, *p;
    if (root == NULL)
    {
        root = createNode(key);
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return; // No duplicates
    }
    p = createNode(key);
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
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

int main()
{
    int keys[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    for (int i = 0; i < n; i++)
        insert(keys[i]);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int searchKey;
    printf("Enter key to search: ");
    scanf("%d", &searchKey);

    Node *found = rSearch(root, searchKey);
    if (found)
        printf("Recursive: Key %d found at address %p\n", searchKey, (void *)found);
    else
        printf("Recursive: Key %d not found\n", searchKey);

    found = iSearch(root, searchKey);
    if (found)
        printf("Iterative: Key %d found at address %p\n", searchKey, (void *)found);
    else
        printf("Iterative: Key %d not found\n", searchKey);

    return 0;
}
