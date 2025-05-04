#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a dynamic array
struct Array
{
    int *A; // Pointer to the array elements
    int size; // Maximum size of the array
    int length; // Current number of elements in the array
};

// Function to display the elements and properties of the array
void display(struct Array a)
{
    printf("\nPrinting the array:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]); // Print each element up to the current length
    }
    printf("\nPrinting the array entire:\n");
    for (int i = 0; i < a.size; i++)
    {
        printf("%d ", a.A[i]); // Print all elements up to the maximum size
    }

    printf("\nLength of the array: %d", a.length); // Print the current length
    printf("\nSize of the array: %d", a.size); // Print the maximum size
}

int main()
{
    struct Array arr; // Declare a dynamic array structure
    printf("Enter size of the array:\n");
    scanf("%d", &arr.size); // Input the maximum size of the array

    // Allocate memory for the array dynamically
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0; // Initialize the current length to 0

    printf("Enter number of elements:");
    int n; // Variable to store the number of elements to input
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]); // Input each element
    }
    arr.length = n; // Update the current length

    display(arr); // Display the array and its properties

    // Free the allocated memory to prevent memory leaks
    free(arr.A);

    return 0;
}