// This code inserts the node at any given position and creates a LL by just using the insert function.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void displayLinkedList(struct Node *p);
void insertNode(struct Node *&p);

int main()
{
    int n = 0;
    cout << "Enter number of node:\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insertNode(first);
    }
    displayLinkedList(first);
    return 0;
}

void displayLinkedList(struct Node *p)
{
    cout << "\nPrinting the LL:\n";
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
    int data = 0;
    cout << "\nEnter the position (index) and data:\n";
    cin >> pos >> data;

    struct Node *newNode;

    if (pos == 0)
    {
        newNode = new Node();
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
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "\nInvalid position!" << endl;
        }
    }
}
