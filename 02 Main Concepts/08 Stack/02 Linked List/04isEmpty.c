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

int isEmpty()
{
    return top == NULL;
}

int main()
{
    printf("Is Empty: %s\n", isEmpty() ? "Yes" : "No");
    push(10);
    printf("Is Empty: %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
