#include <stdio.h>

// Define the Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum size of the array
    int length; // Current number of elements
};

// Function prototype
void display(int A[], int size);
void max(struct Array arr);
void min(struct Array arr);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array

    display(arr.A, arr.size); // Display array elements
    max(arr);                 // Find and display the maximum element
    min(arr);                 // Find and display the minimum element

    return 0;
}

// Display array elements
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]); // Print each element
    }
    printf("\n");
}

// Find the maximum element
void max(struct Array arr)
{
    int max = arr.A[0]; // Initialize max with the first element
    for (int i = 1; i < arr.length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i]; // Update max if a larger element is found
        }
    }
    printf("Max: %d\n", max); // Print the maximum value
}

// Find the minimum element
void min(struct Array arr)
{
    int min = arr.A[0]; // Initialize min with the first element
    for (int i = 1; i < arr.length; i++)
    {
        if (min > arr.A[i])
        {
            min = arr.A[i]; // Update min if a smaller element is found
        }
    }
    printf("Min: %d\n", min); // Print the minimum value
}