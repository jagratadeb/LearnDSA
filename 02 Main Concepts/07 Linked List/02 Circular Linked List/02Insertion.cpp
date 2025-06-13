#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// Function prototypes
void create(int A[], int n);
void display(struct Node *head);
void insertNode(struct Node *&head, int pos, int data);
int countNodes(struct Node *head);

int main()
{
    int A[] = {10, 20, 40, 50, 60, 70, 80, 90, 100};
    int length = sizeof(A) / sizeof(A[0]);
    create(A, length);

    cout << "Circular Linked List:\n";
    display(head);

    int pos, data;
    cout << "\nEnter the position (index): ";
    cin >> pos;
    cout << "Enter the data: ";
    cin >> data;

    insertNode(head, pos, data);

    cout << "\nUpdated Circular Linked List:\n";
    display(head);

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
void display(struct Node *head)
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
            newNode->next = newNode; // Point to itself
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != head) // Traverse to last node
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode; // Update head to new node
        }
    }
    else // Insert at any position > 0
    {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}
