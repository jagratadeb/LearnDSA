#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void display(struct Node *first);
void create(int arr[], int size);
void createArray(int *&arr, int &n);
struct Node *linearSearch(struct Node *p, int key);

int main()
{
    int *arr;
    int n;
    struct Node *p;
    createArray(arr, n);
    create(arr, n);
    display(first);
    p = linearSearch(first, 55);
    if (p)
    {
        cout << "\nFound " << p->data << " at" << " address " << p;
    }
    else
    {
        cout << "\nNot Found!";
    }
    return 0;
}

void createArray(int *&arr, int &n)
{
    cout << "Enter number of elements:\n";
    cin >> n;
    arr = new int[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void create(int arr[], int size)
{
    struct Node *last, *t;
    first = new Node();
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        t = new Node();
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *first)
{
    struct Node *t;
    t = first;
    cout << "Displaying the Linked List:" << endl;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

struct Node *linearSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}