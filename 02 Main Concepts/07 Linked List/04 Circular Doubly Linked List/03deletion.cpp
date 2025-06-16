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
void deleteNode(struct Node *&head, int pos);
int countNodes(struct Node *head);

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(A, 10);

    cout << "Forward Display:\n";
    display(first);

    deleteNode(first, 0);
    display(first);

    deleteNode(first, 8);
    display(first);

    deleteNode(first, 5);
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
    first->next = first; // Circular link (pointing to itself)
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->prev = last; // Maintain backward link
        t->data = A[i];
        t->next = first; // Maintain circularity
        last->next = t;  // Forward link
        first->prev = t; // Ensure circular doubly linked structure
        last = t;
    }
}

// Display the circular doubly linked list (forward traversal)
void display(struct Node *p)
{
    if (!p)
        return; // Handle empty list case

    struct Node *temp = p;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);
    cout << endl;
}

// Count nodes in the circular linked list
int countNodes(struct Node *head)
{
    if (head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Delete a node at a given index position in the circular doubly linked list
void deleteNode(struct Node *&head, int pos)
{
    if (!head) // Check if list is empty
    {
        cout << "\nList is empty. Nothing to delete.\n";
        return;
    }

    int length = countNodes(head);
    if (pos < 0 || pos >= length) // Validate index position
    {
        cout << "\nIndex out of bounds! Maximum allowed: " << length - 1 << "\n";
        return;
    }

    struct Node *temp = head;

    // Case 1: Deleting first node
    if (pos == 0)
    {
        struct Node *last = head->prev; // Get last node
        head = head->next;              // Move head forward
        last->next = head;              // Link last to new head
        head->prev = last;              // Maintain backward link

        delete temp; // Free memory
        return;
    }

    // Case 2: Deleting any node at index > 0
    for (int i = 0; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp; // Free memory
}
