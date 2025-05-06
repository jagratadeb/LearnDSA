#include <stdio.h>
#include <stdlib.h>

// Array structure
struct Array
{
    int A[10];  // Elements
    int size;   // Max capacity
    int length; // Current count
};

// Display array
void display(struct Array arr)
{
    printf("\n\nDisplaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// Delete element
void delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length) // Check index
    {
        for (int i = index; i < arr->length - 1; i++) // Shift left
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--; // Reduce length
        printf("\nElement deleted at index %d", index);
    }
    else
    {
        printf("\nInvalid Index!");
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5}; // Initialize

    display(arr);    // Show array
    delete(&arr, 2); // Delete element
    delete(&arr, 9); // Delete element (invalid index)
    display(arr);    // Show updated array

    return 0;
}