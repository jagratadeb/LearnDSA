#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Function prototype
void display(struct Array a);
void reverse(struct Array *arr);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10, 9}; // Initialize array

    display(arr);  // Show original array
    reverse(&arr); // Reverse array
    display(arr);  // Show reversed array

    return 0;
}

// Display array elements
void display(struct Array a)
{
    printf("\nArray:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]); // Print element
    }
}

// Reverse array using swapping
void reverse(struct Array *arr)
{
    for (int i = 0; i < (arr->length) / 2; i++) // Loop till middle
    {
        int temp = arr->A[i]; // Swap elements
        arr->A[i] = arr->A[arr->length - 1 - i];
        arr->A[arr->length - 1 - i] = temp;
    }
}