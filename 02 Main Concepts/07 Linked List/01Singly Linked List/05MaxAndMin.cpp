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
void max(struct Node *first);
void min(struct Node *first);

int main()
{
    int *arr;
    int n;
    createArray(arr, n);
    create(arr, n);
    display(first);
    max(first);
    min(first);
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

void max(struct Node *first)
{
    struct Node *t;
    t = first;
    int max = t->data;
    while (t != NULL)
    {
        if (max < t->data)
        {
            max = t->data;
        }
        t = t->next;
    }
    cout << "\nMax: " << max;
}

void min(struct Node *first)
{
    struct Node *t;
    t = first;
    int min = t->data;
    while (t != NULL)
    {
        if (min > t->data)
        {
            min = t->data;
        }
        t = t->next;
    }
    cout << "\nMin: " << min << endl;
}