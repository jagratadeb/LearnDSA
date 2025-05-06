#include <stdio.h>
#include <stdlib.h>

// Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum capacity
    int length; // Current number of elements
};

// Display array elements
void display(struct Array arr)
{
    printf("\n\nDisplaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// Insert element at a specific index
void insert(struct Array *arr, int index, int ele)
{
    if (index >= 0 && index <= arr->length) // Check valid index
    {
        for (int i = arr->length; i > index; i--) // Shift elements
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = ele; // Insert element
        arr->length++;       // Update length
        printf("\n%d inserted at index %d", ele, index);
    }
    else
    {
        printf("\n%d not inserted. (%d is an invalid index!)",ele, index);
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5}; // Initialize array

    insert(&arr, 3, 10); // Insert element
    insert(&arr, 8, 45); // Insert element
    display(arr);        // Display updated array

    return 0;
}