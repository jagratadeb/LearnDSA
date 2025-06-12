#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void displayLinkedList(struct Node *p);
void insertNode(struct Node *&p);
void insertInSortedLL(struct Node *&p, int ele);

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
    insertInSortedLL(first, 18);
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
    static int pos = 0;
    int data = 0;
    cout << "\nEnter the data:\n";
    cin >> data;

    struct Node *newNode;

    if (pos == 0)
    {
        newNode = new Node();
        newNode->data = data;
        newNode->next = p;
        p = newNode;
        first = p;
        pos++;
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
            pos++;
        }
        else
        {
            cout << "\nInvalid position!" << endl;
        }
    }
}

void insertInSortedLL(struct Node *&p, int ele)
{
    struct Node *newNode = new Node();
    newNode->data = ele;
    newNode->next = NULL;

    // If list is empty or new element should be at head
    if (p == NULL || ele <= p->data)
    {
        newNode->next = p;
        p = newNode;
        first = p; // keep global pointer updated
        return;
    }

    struct Node *curr = p;
    // Traverse to find the correct position
    while (curr->next != NULL && curr->next->data < ele)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}
