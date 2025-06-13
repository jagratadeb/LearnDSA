#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

// Function prototypes
void create(int A[], int n);
void display(struct Node *p);
void reverseDisplay(struct Node *p); // Additional function for backward traversal

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    cout << "Forward Display:\n";
    display(first);

    cout << "Reverse Display:\n";
    reverseDisplay(first); // Validate backward linkage

    return 0;
}

// Create a doubly linked list from an array
void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node();
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        t->prev = last; // Maintain backward link
        last->next = t; // Maintain forward link
        last = t;
    }
}

// Display the doubly linked list (forward traversal)
void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        if (p->next == NULL) // Capture last node for reverse traversal
            first = p;
        p = p->next;
    }
    cout << endl;
}

// Display doubly linked list in reverse order (backward traversal)
void reverseDisplay(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        if (p->prev == NULL)
            first = p;
        p = p->prev;
    }
    cout << endl;
}
