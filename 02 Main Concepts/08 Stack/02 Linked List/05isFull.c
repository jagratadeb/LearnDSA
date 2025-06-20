#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

int isFull()
{
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
    printf("Is Full: %s\n", isFull() ? "Yes" : "No");
    return 0;
}
