#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void initDEQueue(struct DEQueue *dq, int size)
{
    dq->size = size;
    dq->front = -1;
    dq->rear = -1;
    dq->Q = (int *)malloc(size * sizeof(int));
}

void freeDEQueue(struct DEQueue *dq)
{
    free(dq->Q);
}

int isEmpty(struct DEQueue *dq)
{
    return dq->front == dq->rear;
}

int isFull(struct DEQueue *dq)
{
    return dq->rear == dq->size - 1;
}

void enqueueFront(struct DEQueue *dq, int x)
{
    if (dq->front < 0)
    {
        printf("DEQueue Overflow at front\n");
    }
    else
    {
        dq->Q[dq->front] = x;
        dq->front--;
    }
}

void enqueueRear(struct DEQueue *dq, int x)
{
    if (isFull(dq))
    {
        printf("DEQueue Overflow at rear\n");
    }
    else
    {
        dq->rear++;
        dq->Q[dq->rear] = x;
    }
}

int dequeueFront(struct DEQueue *dq)
{
    int x = -1;
    if (isEmpty(dq))
    {
        printf("DEQueue Underflow at front\n");
    }
    else
    {
        dq->front++;
        x = dq->Q[dq->front];
    }
    return x;
}

int dequeueRear(struct DEQueue *dq)
{
    int x = -1;
    if (dq->rear == dq->front)
    {
        printf("DEQueue Underflow at rear\n");
    }
    else
    {
        x = dq->Q[dq->rear];
        dq->rear--;
    }
    return x;
}

void display(struct DEQueue *dq)
{
    if (isEmpty(dq))
    {
        printf("DEQueue is empty\n");
        return;
    }
    for (int i = dq->front + 1; i <= dq->rear; i++)
    {
        printf("%d", dq->Q[i]);
        if (i < dq->rear)
        {
            printf(" <- ");
        }
    }
    printf("\n");
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
    struct DEQueue deq;
    initDEQueue(&deq, 10);

    for (int i = 0; i < 5; i++)
    {
        enqueueRear(&deq, A[i]);
    }
    display(&deq);
    enqueueRear(&deq, 11);

    for (int i = 0; i < 5; i++)
    {
        dequeueFront(&deq);
    }
    dequeueFront(&deq);

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        enqueueFront(&deq, B[i]);
    }
    display(&deq);
    enqueueFront(&deq, 10);
    enqueueFront(&deq, 12);

    for (int i = 0; i < 4; i++)
    {
        dequeueRear(&deq);
    }
    display(&deq);
    dequeueRear(&deq);
    dequeueRear(&deq);

    freeDEQueue(&deq);

    return 0;
}