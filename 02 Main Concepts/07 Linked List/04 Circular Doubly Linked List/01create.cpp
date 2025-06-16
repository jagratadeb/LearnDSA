#include <iostream>
using namespace std;

// Node structure for circular doubly linked list
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

// Function prototypes
void create(int A[], int n);
void display(struct Node *p);

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(A, 10);

    cout << "Forward Display:\n";
    display(first);

    return 0;
}

// Create a circular doubly linked list from an array
void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node();
    first->prev = NULL;
    first->data = A[0];
    first->next = first; // Self-link for circularity
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->prev = last; // Maintain backward link
        t->data = A[i];
        t->next = first; // Maintain circularity
        last->next = t;  // Forward link
        first->prev = t; // link the first node back to last
        last = t;
    }
}

// Display the circular doubly linked list (forward traversal)
void display(struct Node *p)
{
    if (!p)
        return; // Handle empty list case

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
    cout << endl;
}
