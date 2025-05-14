#include <stdio.h>

// Define the Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum size of the array
    int length; // Current number of elements
};

// Function prototype
void display(struct Array arr);
int binarySearch(struct Array arr, int key);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array
    display(arr);                                                 // Display array elements

    int key = 11;                                                // Key to search
    printf("%d found at index %d", key, binarySearch(arr, key)); // Perform search
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

// Iterative binary search
int binarySearch(struct Array arr, int key)
{
    int low = 0;
    int high = arr.length - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2; // Calculate mid index
        if (key == arr.A[mid])
        {
            return mid; // Key found
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1; // Search in left half
        }
        else
        {
            low = mid + 1; // Search in right half
        }
    }
    return -1; // Key not found
}
