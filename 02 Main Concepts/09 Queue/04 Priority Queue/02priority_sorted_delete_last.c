#include <stdio.h>
#define MAX 20

// n keeps track of the current number of elements in the queue
// Q is the array that stores the queue elements

// Insert elements in increasing order of priority (smallest first), then delete the last element

// Insert an element in sorted order (increasing)
void insert(int Q[], int n, int x)
{
    if (n >= MAX)
    {
        printf("Queue is full!\n");
        return;
    }
    int i = n - 1;
    // Shift elements to make space for the new element
    while (i >= 0 && Q[i] > x)
    {
        Q[i + 1] = Q[i];
        i--;
    }
    Q[i + 1] = x; // Insert at the correct position
}

// Display all elements in the queue
void display(int Q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

// Delete the last element (lowest priority)
void deleteLast(int n)
{
    if (n == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted element\n");
}

int main()
{
    int Q[MAX];                  // Array to store queue elements
    int n = 0;                   // Number of elements in the queue
    int arr[] = {5, 2, 8, 1, 7}; // Example priorities (1 is highest)
    int size = sizeof(arr) / sizeof(arr[0]);
    // Insert all elements in sorted order
    for (int i = 0; i < size; i++)
    {
        insert(Q, n, arr[i]);
        n++;
    }
    printf("Queue (increasing order): ");
    display(Q, n);
    // Delete the last element (lowest priority)
    if (n > 0)
    {
        deleteLast(n);
        n--;
    }
    printf("Queue after deleting last: ");
    display(Q, n);
    return 0;
}
