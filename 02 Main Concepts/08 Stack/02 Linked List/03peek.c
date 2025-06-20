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

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Peek: %d\n", peek());
    pop();
    printf("Peek: %d\n", peek());
    return 0;
}
