#include <iostream>
using namespace std;

// Node structure for Circular Linked List
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// Function prototypes
void create(int A[], int n);                  // Function to create a circular linked list from an array
void display(struct Node *head);              // Function to display the circular linked list
void deleteNode(struct Node *&head, int pos); // Function to delete a node at a given position
int countNodes(struct Node *head);            // Function to count the number of nodes in the circular linked list

int main()
{
    int A[] = {10, 20, 40, 50, 60, 70, 80, 90, 100};
    int length = sizeof(A) / sizeof(A[0]);
    create(A, length);

    cout << "Circular Linked List:\n";
    display(head);

    int pos;
    cout << "\nEnter the position (index) to delete: ";
    cin >> pos;

    deleteNode(head, pos);

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

    // Creating the remaining nodes while maintaining circular linking
    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = head; // Pointing back to head to maintain circular nature
        last->next = t;
        last = t;
    }
}

// Display the circular linked list
void display(struct Node *head)
{
    if (head == NULL) // Empty list check
        return;

    struct Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head); // Ensure circular traversal
    cout << endl;
}

// Count nodes in the circular linked list
int countNodes(struct Node *head)
{
    if (head == NULL) // If the list is empty, return 0
        return 0;

    int count = 0;
    struct Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head); // Loop terminates when we reach head again

    return count;
}

// Function to delete a node at a given position in the circular linked list
void deleteNode(struct Node *&head, int pos)
{
    if (head == NULL) // If the list is empty, deletion is not possible
    {
        cout << "\nList is empty, nothing to delete.\n";
        return;
    }

    int length = countNodes(head);

    // Validate position to ensure it falls within the range of existing nodes
    if (pos < 0 || pos >= length)
    {
        cout << "\nInvalid position! Maximum allowed index: " << length - 1 << "\n";
        return;
    }

    struct Node *temp = head;

    // Case 1: Deleting the head node
    if (pos == 0)
    {
        if (head->next == head) // If the list has only one node
        {
            delete head;
            head = NULL;
            return;
        }

        // Move `temp` to the last node to correctly update circular linkage
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next; // Maintain circular linkage
        delete head;
        head = temp->next; // Update head to next node
    }
    else
    {
        // Traverse the list to the node just before the target position
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        struct Node *delNode = temp->next; // Identify the node to be deleted
        temp->next = delNode->next;        // Link previous node to the next node
        delete delNode;                    // Delete the unwanted node
    }
}
