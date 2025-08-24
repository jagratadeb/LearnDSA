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

void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int countNode(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countNode(p->lchild);
        y = countNode(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int countLeafNode(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        if (p->lchild == NULL && p->rchild == NULL)
            return 1;
        x = countLeafNode(p->lchild);
        y = countLeafNode(p->rchild);
        return x + y;
    }
    return 0;
}

int countDegree2Node(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countDegree2Node(p->lchild);
        y = countDegree2Node(p->rchild);
        if (p->lchild != NULL && p->rchild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int countHeight(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = countHeight(p->lchild);
        y = countHeight(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    else
        return 0;
}

int main()
{
    create();
    printf("Postorder traversal: ");
    postorder(root);

    printf("\nNode count: ");
    int countOfNode = countNode(root);
    printf("%d\n", countOfNode);

    printf("\nLeaf node count: ");
    int countOfLeafNode = countLeafNode(root);
    printf("%d\n", countOfLeafNode);

    printf("\nNode with two child: ");
    int nodeCountDegree = countDegree2Node(root);
    printf("%d\n", nodeCountDegree);

    printf("\nHeight count: ");
    int height = countHeight(root);
    printf("%d\n", height);

    printf("\n");
    return 0;
}