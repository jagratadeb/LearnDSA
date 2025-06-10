#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void display(struct Node *first);
void create(int arr[], int size);
int *createArray(int &n);
void reverse(struct Node **first);

int main()
{
    int n;
    int *arr = createArray(n);
    create(arr, n);
    display(first);
    reverse(&first);
    display(first);
    return 0;
}

int *createArray(int &n)
{
    cout << "Enter number of elements:\n";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    return arr;
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
    cout << "\nDisplaying the Linked List:" << endl;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

void reverse(struct Node **first)
{
    struct Node *p = *first, *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *first = q;
}