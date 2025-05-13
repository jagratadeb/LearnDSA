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
struct Array *intersectionUnsorted(struct Array *arr1, struct Array *arr2);

int main()
{
    struct Array arr1 = {{3, 5, 10, 4, 6}, 10, 5};
    struct Array arr2 = {{12, 4, 7, 2, 5}, 10, 5};
    struct Array *arr3;

    printf("\nArray 1:\n");
    display(arr1);
    printf("\nArray 2:\n");
    display(arr2);

    arr3 = intersectionUnsorted(&arr1, &arr2);

    printf("\nUnsorted Intersection Array:\n");
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

// Function to find the intersection of two unsorted arrays
struct Array *intersectionUnsorted(struct Array *arr1, struct Array *arr2)
{
    int k = 0; // Pointer for the result array
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); // Allocate memory for the intersection array
    arr3->length = 0; // Initialize the length of the result array
    arr3->size = arr1->length; // Set the size of the result array

    // Find common elements between arr1 and arr2
    for (int i = 0; i < arr2->length; i++)
    {
        for (int j = 0; j < arr1->length; j++)
        {
            if (arr2->A[i] == arr1->A[j]) // Check if the element is common
            {
                arr3->A[k++] = arr2->A[i]; // Add the common element to arr3
            }
        }
    }
    arr3->length = k; // Set the length of the result array
    return arr3; // Return the intersection array
}
