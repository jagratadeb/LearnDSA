#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Function prototype
void display(struct Array arr);
struct Array *merge(struct Array *arr1, struct Array *arr2);

int main()
{
    struct Array arr1 = {{2, 4, 6, 8, 10}, 10, 5};
    struct Array arr2 = {{1, 3, 5, 7, 9}, 10, 5};
    struct Array *arr3;
    arr3 = merge(&arr1, &arr2);

    printf("Display Array 1:\n");
    display(arr1);
    printf("Display Array 2:\n");
    display(arr2);
    printf("Display Merged Array:\n");
    display(*arr3);
    return 0;
}

// Function to display the elements of the array
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element of the array
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to merge two sorted arrays into a single sorted array
struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for arr3
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array)); // Allocate memory for the merged array

    // Merge elements from both arrays in sorted order
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++]; // Add element from arr1 to arr3
        }
        else
        {
            arr3->A[k++] = arr2->A[j++]; // Add element from arr2 to arr3
        }
    }

    // Add remaining elements from arr1, if any
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    // Add remaining elements from arr2, if any
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length + arr2->length; // Set the length of the merged array
    arr3->size = 10; // Set the size of the merged array

    return arr3; // Return the merged array
}