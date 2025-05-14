// Include necessary header files
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an array
struct Array
{
    int A[10]; // Array to store elements
    int size;  // Maximum size of the array
    int length; // Current number of elements in the array
};

// Function prototypes
void display(struct Array arr); // Function to display elements of an array
struct Array *differenceSorted(struct Array *arr1, struct Array *arr2); // Function to find the difference of two sorted arrays

int main()
{
    // Initialize two sorted arrays with predefined elements
    struct Array arr1 = {{3, 4, 5, 6, 10}, 10, 5};
    struct Array arr2 = {{2, 4, 5, 7, 12}, 10, 5};
    struct Array *arr3; // Pointer to store the result array

    // Find the difference of the two sorted arrays
    arr3 = differenceSorted(&arr1, &arr2);

    // Display the first array
    printf("Display Array 1:\n");
    display(arr1);

    // Display the second array
    printf("Display Array 2:\n");
    display(arr2);

    // Display the resulting array
    printf("Sorted difference Array:\n");
    display(*arr3);

    // Free the dynamically allocated memory
    free(arr3);
    return 0;
}

// Function to display elements of an array
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to find the difference of two sorted arrays
struct Array *differenceSorted(struct Array *arr1, struct Array *arr2)
{
    int i = 0; // Index for the first array
    int j = 0; // Index for the second array
    int k = 0; // Index for the result array
    struct Array *arr3; // Pointer to the result array
    arr3 = (struct Array *)malloc(sizeof(struct Array)); // Allocate memory for the result array

    arr3->length = 0; // Initialize the length of the result array

    // Iterate through both arrays to find the difference
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++]; // Add unique elements from the first array
        }
        else if (arr1->A[i] > arr2->A[j])
        {
            j++; // Skip elements in the second array
        }
        else
        {
            i++; // Skip common elements in both arrays
            j++;
        }
    }

    // Add remaining elements from the first array
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k; // Update the length of the result array
    arr3->size = arr1->length; // Set the size of the result array

    return arr3; // Return the result array
}