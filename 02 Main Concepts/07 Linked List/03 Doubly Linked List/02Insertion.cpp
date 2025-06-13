#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first;

void createLinkedList(int arr[], int n);
void displayLinkedList(struct Node *p);
void insertNode(struct Node *&p);

int main()
{
    int A[] = {10, 20, 40, 50, 60, 70, 80, 90, 100};
    int length = sizeof(A) / sizeof(A[0]);
    createLinkedList(A, length);

    displayLinkedList(first);

    insertNode(first);

    displayLinkedList(first);
    return 0;
}

void createLinkedList(int arr[], int n)
{
    struct Node *t, *last;
    first = new Node();
    first->prev = NULL;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->prev = last;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayLinkedList(struct Node *p)
{
    cout << "\nForward printing:\n";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void insertNode(struct Node *&p)
{
    int pos = 0;
    cout << "\nEnter the position (index):\n";
    cin >> pos;

    int data = 0;
    cout << "Enter the data:\n";
    cin >> data;

    struct Node *newNode;

    if (pos == 0)
    {
        newNode = new Node();
        newNode->prev = NULL;
        newNode->data = data;
        newNode->next = p;
        p = newNode;
        first = p;
    }
    else if (pos > 0)
    {
        struct Node *temp = p;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            newNode = new Node();
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            newNode->data = data;
            if (newNode->next != NULL)
            {
                newNode->next->prev = newNode;
            }
        }
        else
        {
            cout << "\nInvalid position!" << endl;
        }
    }
}
