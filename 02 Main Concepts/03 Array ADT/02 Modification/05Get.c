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
void get(struct Array arr, int index);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array

    display(arr.A, arr.size); // Display array elements
    get(arr, 8);              // Get value at index 8
    get(arr, 9);              // Get value at index 9
    get(arr, 10);             // Attempt to get value at an invalid index

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

// Get the value at a specific index
void get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.size)
    {
        printf("get(%d) = %d\n", index, arr.A[index]); // Print the value at the index
    }
    else
    {
        printf("Invalid Index\n"); // Handle invalid index
    }
}