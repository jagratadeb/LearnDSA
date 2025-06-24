#include <stdio.h>
#define MAX 20

// n keeps track of the current number of elements in the queue
// Q is the array that stores the queue elements

// Insert elements in the order given, then delete the element with the highest priority (smallest value)

// Insert an element at the end of the queue
void insert(int Q[], int n, int x)
{
    // n is the current number of elements in the queue
    if (n >= MAX)
    {
        printf("Queue is full!\n");
        return;
    }
    Q[n] = x; // Insert at the end
}

// Display all elements in the queue
void display(int Q[], int n)
{
    // n is the current number of elements in the queue
    for (int i = 0; i < n; i++)
    {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

// Delete the element with the highest priority (smallest value)
void deleteMaxPriority(int Q[], int *n)
{
    // *n is the current number of elements in the queue
    if (*n == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    int minIdx = 0;
    // Find the index of the smallest element
    for (int i = 1; i < *n; i++)
    {
        if (Q[i] < Q[minIdx])
        {
            minIdx = i;
        }
    }
    printf("Deleted element with max priority: %d\n", Q[minIdx]);
    // Shift elements to fill the gap
    for (int i = minIdx; i < *n - 1; i++)
    {
        Q[i] = Q[i + 1];
    }
    (*n)--; // Decrease the count of elements
}

int main()
{
    int Q[MAX];                  // Array to store queue elements
    int n = 0;                   // Number of elements in the queue
    int arr[] = {5, 2, 8, 1, 7}; // Example priorities (1 is highest)
    int size = sizeof(arr) / sizeof(arr[0]);
    // Insert all elements
    for (int i = 0; i < size; i++)
    {
        insert(Q, n, arr[i]);
        n++;
    }
    printf("Queue: ");
    display(Q, n);
    // Delete the element with the highest priority
    deleteMaxPriority(Q, &n);
    printf("Queue after deleting max priority: ");
    display(Q, n);
    return 0;
}
