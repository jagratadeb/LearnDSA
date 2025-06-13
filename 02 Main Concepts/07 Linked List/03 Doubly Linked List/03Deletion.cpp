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
void deleteNode(struct Node *&p);

int main()
{
    int A[] = {10, 20, 40, 50, 60, 70, 80, 90, 100};
    int length = sizeof(A) / sizeof(A[0]);
    createLinkedList(A, length);

    displayLinkedList(first);

    deleteNode(first);

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

void deleteNode(struct Node *&p)
{
    int pos = 0;
    cout << "\nEnter the position (index):\n";
    cin >> pos;

    if (pos == 0)
    {
        p = p->next;
        first = p;
        delete p->prev;
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
            struct Node *delNode = temp->next;
            temp->next = temp->next->next;
            if (delNode->next != NULL)
            {
                temp->next->next->prev = temp;
            }
            delete delNode;
        }
        else
        {
            cout << "\nInvalid position!" << endl;
        }
    }
}
