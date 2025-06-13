#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n);
void isLooped(struct Node *first);

int main()
{
    int A[] = {10, 20, 40, 50, 60, 70};
    create(A, 6);

    struct Node *t1 = first, *t2 = first;

    // Move t1 to the third node (40)
    for (int i = 0; i < 2; i++)
        t1 = t1->next;

    // Move t2 to the last node (70)
    for (int i = 0; i < 5; i++)
        t2 = t2->next;

    // Create the loop: Set t2's next to t1
    t2->next = t1;

    isLooped(first);

    return 0;
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void isLooped(struct Node *first)
{
    struct Node *slow, *fast;
    slow = fast = first;

    do
    {
        slow = slow->next;
        fast = fast->next;
        fast = (fast != NULL) ? fast->next : NULL;
    } while (slow && fast && slow != fast);
    if (slow == fast)
    {
        cout << "Yes, loop found." << endl;
    }
    else
    {
        cout << "No, loop not found." << endl;
    }
}