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
void insertNode(struct Node *&head, int pos, int data);
int countNodes(struct Node *head);

int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(A, 10);

    cout << "Forward Display:\n";
    display(first);

    insertNode(first, 0, 1000); // Insert at beginning
    display(first);

    insertNode(first, 0, 2000); // Another insertion at beginning
    display(first);

    insertNode(first, 4, 4000); // Insert in middle
    display(first);

    insertNode(first, 13, 9000); // Insert at last position
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

// Insert a node at a given position in the circular linked list
void insertNode(struct Node *&head, int pos, int data)
{
    if (pos < 0)
    {
        cout << "\nEnter a valid positive position.\n";
        return;
    }

    int length = countNodes(head);
    if (pos > length)
    {
        cout << "\nPosition out of bounds! Maximum allowed: " << length << "\n";
        return;
    }

    struct Node *newNode = new Node();
    newNode->data = data;

    if (pos == 0) // Insert at beginning
    {
        if (head == NULL) // If list is empty
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        }
        else
        {
            struct Node *last = head->prev; // Get last node
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode; // Update head to new node
        }
    }
    else // Insert at any position > 0
    {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}


