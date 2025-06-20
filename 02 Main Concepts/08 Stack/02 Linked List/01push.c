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

int main()
{
    push(10);
    push(20);
    push(30);
    struct Node *p = top;
    printf("Stack contents: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
