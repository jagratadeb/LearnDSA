#include <stdio.h>

// Define the Array structure
struct Array
{
    int A[10]; // Array elements
    int size;  // Maximum size of the array
    int length; // Current number of elements
};

// Display array elements
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]); // Print each element
    }
    printf("\n");
}

// Set a value at a specific index
void set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->size)
    {
        arr->A[index] = value; // Update the value at the index
        printf("set(A[%d]) = %d\n", index, arr->A[index]); // Print the updated value
    }
    else
    {
        printf("Invalid Index\n"); // Handle invalid index
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array

    display(arr.A, arr.size); // Display array elements
    set(&arr, 8, 19); // Set value at index 8
    set(&arr, 9, 20); // Set value at index 9
    set(&arr, 10, 21); // Attempt to set value at an invalid index
    display(arr.A, arr.size); // Display updated array elements

    return 0;
}