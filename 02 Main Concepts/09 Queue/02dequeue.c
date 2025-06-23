#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *Q;
};

void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q);
void queueDisplay(struct Queue *q);

int main()
{
    struct Queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    enqueue(&q, 25);
    queueDisplay(&q);

    dequeue(&q);
    dequeue(&q);

    queueDisplay(&q);

    return 0;
}

void enqueue(struct Queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q)
{
    int data = -1;
    if (q->rear == -1 && q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        q->front++;
        data = q->Q[q->front];
    }
    return data;
}

void queueDisplay(struct Queue *q)
{
    if (q->rear == -1 && q->front == -1 || q->front > q->rear)
    {
        printf("Nothing to display: Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d ", q->Q[i]);
        }
        printf("\n");
    }
}