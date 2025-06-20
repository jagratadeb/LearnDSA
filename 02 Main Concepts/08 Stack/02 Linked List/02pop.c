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

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop()); // Should print stack is empty
    return 0;
}
