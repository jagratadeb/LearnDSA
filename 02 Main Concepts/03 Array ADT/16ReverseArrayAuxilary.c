#include <stdio.h>
#include <stdlib.h>

// Structure to represent an array
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum size of the array
    int length; // Current number of elements in the array
};

// Function to display the elements of the array
void display(struct Array a)
{
    printf("\nPrinting the array:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]); // Print each element
    }
}

// Function to reverse the array using an auxiliary array
void reverse(struct Array *arr)
{
    int B[10]; // Auxiliary array
    for (int i = 0; i < arr->length; i++)
    {
        B[i] = arr->A[arr->length - 1 - i]; // Copy elements in reverse order
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i]; // Copy back to original array
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    display(arr);
    reverse(&arr);
    display(arr);

    return 0;
}