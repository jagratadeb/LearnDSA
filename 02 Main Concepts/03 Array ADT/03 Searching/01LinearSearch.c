#include <stdio.h>

// Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum capacity
    int length; // Current number of elements
};

// Function prototype
void display(struct Array arr);
int linearSearch(struct Array arr, int key);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array

    display(arr); // Display array elements

    int ele = 5; // Element to search for

    printf("\n%d is located at index %d\n", ele, linearSearch(arr, ele)); // Print search result

    return 0;
}

// Display all elements in the array
void display(struct Array arr)
{
    printf("\n\nDisplaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// Perform linear search for a key in the array
int linearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i]) // Check if current element matches the key
        {
            return i; // Return index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}