#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int data)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q)
{
    int data = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        data = q->Q[q->front];
    }
    return data;
}

void queueDisplay(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        int i = (q->front + 1);
        printf("Queue elements: ");
        do
        {
            printf("%d ", q->Q[i]);
            i = (i + 1) % q->size;
        } while (i != (q->rear + 1) % q->size);
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    q.size = 10;
    q.front = q.rear = 0;
    q.Q = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    queueDisplay(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    queueDisplay(&q);

    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);
    queueDisplay(&q);

    return 0;
}