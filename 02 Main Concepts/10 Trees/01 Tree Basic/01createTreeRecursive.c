#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

typedef struct Node Node;

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q; // Q is a pointer to pointer, stores addresses of Node
};

void initQueue(struct Queue *q, int size)
{
    q->size = size + 1; // for circular queue
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size * sizeof(Node *)); // allocate for Node* (addresses)
}

void enqueue(struct Queue *q, Node *data)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data; // store address directly
    }
}

Node *dequeue(struct Queue *q)
{
    Node *data = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        data = q->Q[q->front]; // get address directly
    }
    return data;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

Node *root = NULL;

void create()
{
    Node *p, *t;
    int x;
    struct Queue q;
    initQueue(&q, 100);
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (Node *)malloc(sizeof(Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isEmpty(&q))
    {
        p = dequeue(&q);
        printf("Enter value for lchild of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (Node *)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter value for rchild of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (Node *)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
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

void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    create();
    printf("Preorder traversal: ");
    preorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}