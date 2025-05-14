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
struct Array *unionUnsorted(struct Array *arr1, struct Array *arr2);

int main()
{
    struct Array arr1 = {{3, 5, 10, 4, 6}, 10, 5};
    struct Array arr2 = {{12, 4, 7, 2, 5}, 10, 5};
    struct Array *arr3;

    printf("\nArray 1:\n");
    display(arr1);
    printf("\nArray 2:\n");
    display(arr2);

    arr3 = unionUnsorted(&arr1, &arr2);

    printf("\nUnsorted Union Array:\n");
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

// Function to find the union of two unsorted arrays
struct Array *unionUnsorted(struct Array *arr1, struct Array *arr2)
{
    int k = 0; // Pointer for the result array
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); // Allocate memory for the union array
    arr3->length = 0; // Initialize the length of the result array
    arr3->size = arr1->length + arr2->length; // Set the size of the result array

    // Copy all elements from arr1 to arr3
    for (int i = 0; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
        arr3->length++;
    }

    // Add elements from arr2 to arr3 if they are not duplicates
    for (int i = 0; i < arr2->length; i++)
    {
        int isDuplicate = 0; // Flag to check for duplicates
        for (int j = 0; j < arr1->length; j++)
        {
            if (arr2->A[i] == arr1->A[j]) // Check if the element is a duplicate
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) // If not a duplicate, add to arr3
        {
            arr3->A[k++] = arr2->A[i];
            arr3->length++;
        }
    }
    return arr3; // Return the union array
}
