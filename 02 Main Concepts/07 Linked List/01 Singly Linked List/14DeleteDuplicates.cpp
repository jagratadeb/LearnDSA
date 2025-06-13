#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void createArray(int *&arr, int &n);
void createLinkedList(int arr[], int n);
void displayLinkedList(struct Node *p);
void deleteDuplicate(struct Node *&p);

int main()
{
    int *arr;
    int n;
    createArray(arr, n);
    createLinkedList(arr, n);
    displayLinkedList(first);
    deleteDuplicate(first);
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

void deleteDuplicate(struct Node *&p)
{
    struct Node *curr = p;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            struct Node *deleteNode = curr->next;
            int data = deleteNode->data;
            cout << "Deleted: " << data << endl;
            curr->next = deleteNode->next;
            delete deleteNode;
        }
        else
        {
            curr = curr->next;
        }
    }
}