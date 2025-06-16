#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Function declarations
void create(int A[], int n);
void create2(int A[], int n);
void Display(struct Node *p);
void Concat(struct Node *p, struct Node *q);
void Merge(struct Node *p, struct Node *q);
int Count(struct Node *p);
void Sort(struct Node *head);
int isPalindrome(struct Node *head);
void PrintDuplicates(struct Node *p);
void RemoveDuplicates(struct Node *p);
void Reverse(struct Node **head);

int main()
{
    int choice;
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 10, 10, 55};

    create(A, 5);
    create2(B, 5);

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Display list\n");
        printf("2. Count nodes\n");
        printf("3. Check palindrome\n");
        printf("4. Print duplicates\n");
        printf("5. Remove duplicates\n");
        printf("6. Reverse list\n");
        printf("7. Sort list\n");
        printf("8. Concat first and second\n");
        printf("9. Merge first and second\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Display(third);
            break;
        case 2:
            printf("Total nodes: %d\n", Count(third));
            break;
        case 3:
            printf("Palindrome: %s\n", isPalindrome(third) ? "Yes" : "No");
            break;
        case 4:
            PrintDuplicates(third);
            break;
        case 5:
            RemoveDuplicates(third);
            printf("After removing duplicates:\n");
            Display(third);
            break;
        case 6:
            Reverse(&third);
            printf("After reversing:\n");
            Display(third);
            break;
        case 7:
            Sort(third);
            printf("After sorting:\n");
            Display(third);
            break;
        case 8:
            Concat(first, second);
            printf("After concatenation:\n");
            Display(third);
            break;
        case 9:
            Merge(first, second);
            printf("After merging (sorted):\n");
            Display(third);
            break;
        case 10:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Create first list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Create second list
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Display any list
void Display(struct Node *p)
{
    if (!p)
    {
        printf("List is empty.\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Concatenate second list at end of first
void Concat(struct Node *p, struct Node *q)
{
    if (!p)
    {
        third = q;
        return;
    }

    struct Node *result = (struct Node *)malloc(sizeof(struct Node));
    result->data = p->data;
    result->next = NULL;
    third = result;

    struct Node *last = third;
    p = p->next;

    while (p)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = p->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        p = p->next;
    }

    while (q)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = q->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        q = q->next;
    }
}

// Merge two sorted lists into third
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last = NULL;
    third = NULL;

    if (!p)
    {
        third = q;
        return;
    }
    if (!q)
    {
        third = p;
        return;
    }

    if (p->data < q->data)
    {
        third = last = (struct Node *)malloc(sizeof(struct Node));
        third->data = p->data;
        third->next = NULL;
        p = p->next;
    }
    else
    {
        third = last = (struct Node *)malloc(sizeof(struct Node));
        third->data = q->data;
        third->next = NULL;
        q = q->next;
    }

    while (p && q)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        if (p->data < q->data)
        {
            temp->data = p->data;
            p = p->next;
        }
        else
        {
            temp->data = q->data;
            q = q->next;
        }
        last->next = temp;
        last = temp;
    }

    while (p)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = p->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        p = p->next;
    }

    while (q)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = q->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        q = q->next;
    }
}

// Count nodes
int Count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Sort list using bubble sort
void Sort(struct Node *head)
{
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Check if list is palindrome
int isPalindrome(struct Node *head)
{
    int arr[1000], i = 0, j;
    struct Node *p = head;
    while (p)
    {
        arr[i++] = p->data;
        p = p->next;
    }
    for (j = 0; j < i / 2; j++)
    {
        if (arr[j] != arr[i - j - 1])
            return 0;
    }
    return 1;
}

// Print duplicates in sorted list
void PrintDuplicates(struct Node *p)
{
    int lastDuplicate = -1;
    while (p && p->next)
    {
        if (p->data == p->next->data && p->data != lastDuplicate)
        {
            printf("Duplicate: %d\n", p->data);
            lastDuplicate = p->data;
        }
        p = p->next;
    }
}

// Remove duplicates from sorted list
void RemoveDuplicates(struct Node *p)
{
    struct Node *q = p->next;
    while (q)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

// Reverse a linked list
void Reverse(struct Node **head)
{
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
