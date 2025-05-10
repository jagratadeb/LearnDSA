#include <stdio.h>
#include <stdlib.h>

// Define a structure for a dynamic array
struct Array
{
    int *A;     // Pointer to dynamically allocated array
    int size;   // Maximum size of the array
    int length; // Current number of elements in the array
};

// Function prototype for displaying the array
void display(struct Array a);

int main()
{
    struct Array arr; // Declare a dynamic array structure

    // Prompt user to enter the size of the array
    printf("Enter size of the array:\n");
    scanf("%d", &arr.size); // Input the maximum size of the array

    // Allocate memory for the array dynamically
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0; // Initialize the current length to 0

    // Prompt user to enter the number of elements to be added
    printf("Enter number of elements:");
    int n; // Variable to store the number of elements to input
    scanf("%d", &n);

    // Input the elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]); // Input each element
    }
    arr.length = n; // Update the current length of the array

    // Display the array and its properties
    display(arr);

    // Free the allocated memory to prevent memory leaks
    free(arr.A);

    return 0; // End of the program
}

// Function to display the elements and properties of the array
void display(struct Array a)
{
    printf("\nArray elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]); // Print each element in the array
    }

    printf("\nFull array:\n");
    for (int i = 0; i < a.size; i++)
    {
        printf("%d ", a.A[i]); // Print all elements including uninitialized ones
    }

    // Display the current length and maximum size of the array
    printf("\nLength: %d", a.length); // Current number of elements
    printf("\nSize: %d", a.size);     // Maximum size of the array
}