#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// Function prototypes
void create(int A[], int n);
void Display(struct Node *head);

int main()
{
    int A[] = {10, 20, 40, 50, 60, 70, 80, 90, 100};
    int length = sizeof(A) / sizeof(A[0]);
    create(A, length);

    cout << "Circular Linked List:\n";
    Display(head);

    return 0;
}

// Create a circular linked list from an array
void create(int A[], int n)
{
    struct Node *t, *last;
    head = new Node();
    head->data = A[0];
    head->next = head; // Circular connection
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = head; // Maintain circularity
        last->next = t;
        last = t;
    }
}

// Display the circular linked list
void Display(struct Node *head)
{
    struct Node *p = head;
    if (head == NULL)
        return;

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}