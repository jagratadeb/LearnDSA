#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int n);
void displayLinkedList(struct Node *head);
struct Node *reverse(struct Node *head);

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    struct Node *head = createLinkedList(A, sizeof(A) / sizeof(A[0]));

    cout << "Original List:\n";
    displayLinkedList(head);

    head = reverse(head);

    cout << "Reversed List:\n";
    displayLinkedList(head);

    return 0;
}

struct Node *createLinkedList(int arr[], int n)
{
    struct Node *head = new struct Node;
    head->prev = NULL;
    head->data = arr[0];
    head->next = NULL;
    struct Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        struct Node *t = new struct Node;
        t->prev = tail;
        t->data = arr[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }

    return head;
}

void displayLinkedList(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

struct Node *reverse(struct Node *head)
{
    struct Node *p = head, *temp = NULL;

    while (p != NULL)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }

    // The new head should be the last processed valid node
    if (temp != NULL)
        head = temp->prev;

    return head;
}