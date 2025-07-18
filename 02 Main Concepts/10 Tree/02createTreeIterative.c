#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

// Queue for level order tree creation and traversal
typedef struct QueueNode
{
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front, *rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, Node *data)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node *dequeue(Queue *q)
{
    if (isQueueEmpty(q))
        return NULL;
    QueueNode *temp = q->front;
    Node *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Stack for iterative traversals
typedef struct StackNode
{
    Node *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

int isStackEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, Node *data)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
}

Node *pop(Stack *s)
{
    if (isStackEmpty(s))
        return NULL;
    StackNode *temp = s->top;
    Node *data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

Node *stackTop(Stack *s)
{
    if (isStackEmpty(s))
        return NULL;
    return s->top->data;
}

// For iterative postorder (using long int for visited flag)
typedef struct LStackNode
{
    long int data;
    struct LStackNode *next;
} LStackNode;

typedef struct LStack
{
    LStackNode *top;
} LStack;

void initLStack(LStack *s)
{
    s->top = NULL;
}

int isLStackEmpty(LStack *s)
{
    return s->top == NULL;
}

void lpush(LStack *s, long int data)
{
    LStackNode *temp = (LStackNode *)malloc(sizeof(LStackNode));
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
}

long int lpop(LStack *s)
{
    if (isLStackEmpty(s))
        return 0;
    LStackNode *temp = s->top;
    long int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

long int lstackTop(LStack *s)
{
    if (isLStackEmpty(s))
        return 0;
    return s->top->data;
}

Node *root = NULL;

void CreateTree()
{
    Node *p, *t;
    int x;
    Queue q;
    initQueue(&q);

    root = (Node *)malloc(sizeof(Node));
    printf("Enter root data: ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(&q, root);

    while (!isQueueEmpty(&q))
    {
        p = dequeue(&q);

        printf("Enter left child data of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (Node *)malloc(sizeof(Node));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child data of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (Node *)malloc(sizeof(Node));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Levelorder()
{
    Queue q;
    Node *p;
    if (root == NULL)
        return;
    printf("%d, ", root->data);
    initQueue(&q);
    enqueue(&q, root);

    while (!isQueueEmpty(&q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d, ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d, ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
    printf("\n");
}

void iterativePreorder()
{
    Stack stk;
    Node *p = root;
    initStack(&stk);
    while (p != NULL || !isStackEmpty(&stk))
    {
        if (p != NULL)
        {
            printf("%d, ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterativeInorder()
{
    Stack stk;
    Node *p = root;
    initStack(&stk);
    while (p != NULL || !isStackEmpty(&stk))
    {
        if (p != NULL)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d, ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterativePostorder()
{
    LStack stk;
    Node *p = root;
    long int temp;
    initLStack(&stk);
    while (p != NULL || !isLStackEmpty(&stk))
    {
        if (p != NULL)
        {
            lpush(&stk, (long int)p);
            p = p->lchild;
        }
        else
        {
            temp = lpop(&stk);
            if (temp > 0)
            {
                lpush(&stk, -temp);
                p = ((Node *)temp)->rchild;
            }
            else
            {
                printf("%d, ", ((Node *)(-1 * temp))->data);
                p = NULL;
            }
        }
    }
    printf("\n");
}

int main()
{
    CreateTree();
    printf("\n");

    printf("Levelorder: ");
    Levelorder();

    printf("Iterative Preorder: ");
    iterativePreorder();

    printf("Iterative Inorder: ");
    iterativeInorder();

    printf("Iterative Postorder: ");
    iterativePostorder();

    return 0;
}