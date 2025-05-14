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
struct Array *differenceUnsorted(struct Array *arr1, struct Array *arr2); // Function to find the difference of two unsorted arrays

int main()
{
    // Initialize two arrays with predefined elements
    struct Array arr1 = {{3, 5, 10, 4, 6}, 10, 5};
    struct Array arr2 = {{12, 4, 7, 2, 5}, 10, 5};
    struct Array *arr3; // Pointer to store the result array

    // Display the first array
    printf("\nArray 1:\n");
    display(arr1);

    // Display the second array
    printf("\nArray 2:\n");
    display(arr2);

    // Find the difference of the two arrays
    arr3 = differenceUnsorted(&arr1, &arr2);

    // Display the resulting array
    printf("\nUnsorted difference Array:\n");
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

// Function to find the difference of two unsorted arrays
struct Array *differenceUnsorted(struct Array *arr1, struct Array *arr2)
{
    int k = 0; // Index for the result array
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); // Allocate memory for the result array
    arr3->length = 0; // Initialize the length of the result array
    arr3->size = arr1->length; // Set the size of the result array

    // Iterate through each element of the first array
    for (int i = 0; i < arr1->length; i++)
    {
        int isDuplicate = 0; // Flag to check if the element is in the second array

        // Check if the current element exists in the second array
        for (int j = 0; j < arr2->length; j++)
        {
            if (arr1->A[i] == arr2->A[j])
            {
                isDuplicate = 1; // Mark as duplicate if found
                break;
            }
        }

        // If the element is not a duplicate, add it to the result array
        if (!isDuplicate)
        {
            arr3->A[k++] = arr1->A[i];
            arr3->length++; // Increment the length of the result array
        }
    }

    return arr3; // Return the result array
}
