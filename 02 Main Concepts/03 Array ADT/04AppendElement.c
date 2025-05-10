#include <stdio.h>
#include <stdlib.h>

// Array structure
struct Array
{
    int A[10];  // Elements
    int size;   // Max size
    int length; // Current element count
};

// Function prototype
void display(struct Array arr);
void append(struct Array *arr, int ele);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5}; // Initialize array

    append(&arr, 100); // Append elements
    append(&arr, 101);
    append(&arr, 102);
    append(&arr, 103);
    append(&arr, 104);
    append(&arr, 105);

    display(arr); // Show array

    return 0;
}

// Function to append
void append(struct Array *arr, int ele)
{
    if (arr->length < arr->size) // Check space
    {
        arr->A[arr->length++] = ele; // Add element
        printf("\n%d has been appended.", ele);
    }
    else
    {
        printf("\n%d has not been appended (no space left in array).", ele);
    }
}


// Function to display the array
void display(struct Array arr)
{
    printf("\n\nDisplaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}