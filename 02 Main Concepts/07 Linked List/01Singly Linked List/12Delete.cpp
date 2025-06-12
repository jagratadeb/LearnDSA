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
void deleteNode(struct Node *&p);
int countNode(struct Node *first);
int main()
{
    int *arr;
    int n;
    createArray(arr, n);
    createLinkedList(arr, n);
    displayLinkedList(first);
    deleteNode(first);
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

int countNode(struct Node *first)
{
    int count = 0;
    struct Node *t = first;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

void deleteNode(struct Node *&p)
{
    int pos;
    cout << "\nEnter the position (index) to delete:" << endl;
    cin >> pos;

    int total = countNode(p);
    if (p == NULL)
    {
        cout << "\nList is empty!" << endl;
        return;
    }
    if (pos < 0 || pos >= total)
    {
        cout << "\nInvalid position!" << endl;
        return;
    }

    // Deleting head node
    if (pos == 0)
    {
        struct Node *temp = p;
        p = p->next;
        delete temp;
        first = p;
        return;
    }
    // Traverse to node before the one to delete
    struct Node *prev = p;
    struct Node *curr = p;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}
