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
struct Array *intersectionSorted(struct Array *arr1, struct Array *arr2);

int main()
{
    struct Array arr1 = {{3, 4, 5, 6, 10}, 10, 5};
    struct Array arr2 = {{2, 4, 5, 7, 12}, 10, 5};
    struct Array *arr3;
    arr3 = intersectionSorted(&arr1, &arr2);

    printf("Display Array 1:\n");
    display(arr1);
    printf("Display Array 2:\n");
    display(arr2);
    printf("Sorted Intersection Array:\n");
    display(*arr3);

    free(arr3);
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

// Function to find the intersection of two sorted arrays
struct Array *intersectionSorted(struct Array *arr1, struct Array *arr2)
{
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for arr3
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array)); // Allocate memory for the intersection array

    arr3->length = 0; // Initialize the length of the result array
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++; // Move pointer i forward
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++; // Move pointer j forward
        }
        else
        {
            arr3->A[k++] = arr1->A[i++]; // Add common element to arr3
            j++; // Move pointer j forward
        }
    }
    arr3->length = k; // Set the length of the result array
    arr3->size = arr1->length; // Set the size of the result array

    return arr3; // Return the intersection array
}