#include <stdio.h>

// Define the Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum size of the array
    int length; // Current number of elements
};

// Function prototypes
int recursiveBinarySearch(int arr[], int l, int h, int key);
void display(struct Array arr);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array
    display(arr);                                                 // Display array elements

    int key = 1;                                                      // Key to search
    int index = recursiveBinarySearch(arr.A, 0, arr.length - 1, key); // Perform search

    if (index != -1)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found in the array\n", key);

    return 0;
}

// Display array elements
void display(struct Array arr)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

// Pure recursive binary search ("pure" as it has no loops)
int recursiveBinarySearch(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1; // Base case: key not found

    int mid = (l + h) / 2;

    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        return recursiveBinarySearch(arr, l, mid - 1, key);
    else
        return recursiveBinarySearch(arr, mid + 1, h, key);
}
