#include <stdio.h>
#define MAX 20

// Structure for a simple queue of characters
struct Queue
{
    char data[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

void enqueue(struct Queue *q, char x)
{
    if (q->rear >= MAX - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = x;
}

char dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return '\0';
    }
    q->front++;
    return q->data[q->front];
}

void display(struct Queue *q, int qnum)
{
    printf("Queue %d: ", qnum);
    if (isEmpty(q))
    {
        printf("(empty)\n");
        return;
    }
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%c ", q->data[i]);
    }
    printf("\n");
}

int main()
{
    // Given elements and priorities
    char elements[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int priorities[] = {1, 1, 2, 3, 2, 1, 2, 3, 2, 2};
    int n = sizeof(elements) / sizeof(elements[0]);

    // Create 3 queues for priorities 1, 2, 3
    struct Queue q1, q2, q3;
    initQueue(&q1);
    initQueue(&q2);
    initQueue(&q3);

    // Insert elements into their respective queues
    for (int i = 0; i < n; i++)
    {
        if (priorities[i] == 1)
            enqueue(&q1, elements[i]);
        else if (priorities[i] == 2)
            enqueue(&q2, elements[i]);
        else if (priorities[i] == 3)
            enqueue(&q3, elements[i]);
    }

    // Display all queues
    display(&q1, 1);
    display(&q2, 2);
    display(&q3, 3);

    // Deletion logic: always delete from highest priority non-empty queue
    printf("\nDeleting elements in priority order:\n");
    for (int i = 0; i < n; i++)
    {
        char deleted = '\0';
        if (!isEmpty(&q1))
            deleted = dequeue(&q1);
        else if (!isEmpty(&q2))
            deleted = dequeue(&q2);
        else if (!isEmpty(&q3))
            deleted = dequeue(&q3);
        if (deleted != '\0')
            printf("Deleted: %c\n", deleted);
    }
    return 0;
}
