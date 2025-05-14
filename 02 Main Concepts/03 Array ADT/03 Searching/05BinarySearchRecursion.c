#include <stdio.h>

// Define the Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum size of the array
    int length; // Current number of elements
};

// Function prototype
int recursiveBinarySearch(int arr[], int l, int h, int key);
void display(struct Array arr);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array
    display(arr);                                                 // Display array elements

    int key = 1;                                                                           // Key to search
    printf("%d found at index %d", key, recursiveBinarySearch(arr.A, 0, arr.length, key)); // Perform search
    return 0;
}

// Display array elements
void display(struct Array arr)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element
    }
    printf("\n");
}

// Recursive binary search
int recursiveBinarySearch(int arr[], int l, int h, int key)
{
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2; // Calculate mid index
        if (key == arr[mid])
        {
            return mid; // Key found
        }
        else if (key < arr[mid])
        {
            return recursiveBinarySearch(arr, l, mid - 1, key); // Search in left half
        }
        else
        {
            return recursiveBinarySearch(arr, mid + 1, h, key); // Search in right half
        }
    }
    return -1; // Key not found
}
