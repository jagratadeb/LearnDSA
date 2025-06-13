#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void createArray(int *&arr, int &n);
void createLinkedList(int arr[], int n);
void displayLinkedList(struct Node *p);
void insertNode(struct Node *&p);

int main()
{
    int *arr;
    int n;
    createArray(arr, n);
    createLinkedList(arr, n);
    displayLinkedList(first);
    insertNode(first);
    displayLinkedList(first);
    return 0;
}

void createArray(int *&arr, int &n)
{
    cout << "Enter the number of elements:\n";
    cin >> n;
    arr = new int[n];
    cout << "\nEnter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void createLinkedList(int arr[], int n)
{
    struct Node *t, *last;
    first = new Node();
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
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
    cout << "\nEnter the position (index):\n";
    cin >> pos;

    int data = 0;
    cout << "Enter the data:\n";
    cin >> data;

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
