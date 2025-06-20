#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is full\n");
    }
    else
    {
        t->data = data;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int data = -1;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        data = t->data;
        free(t);
    }
    return data;
}

void display()
{
    struct Node *p = top;
    printf("Stack contents: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return top->data;
    }
}

int isEmpty()
{
    return top == NULL;
}

int isFull()
{
    // For a linked list stack, isFull only if malloc fails
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        return 1; // Full
    }
    else
    {
        free(t);
        return 0; // Not full
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    printf("Popped: %d\n", pop());
    display();
    printf("Peek: %d\n", peek());
    printf("Is Empty: %s\n", isEmpty() ? "Yes" : "No");
    printf("Is Full: %s\n", isFull() ? "Yes" : "No");
    return 0;
}