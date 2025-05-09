#include <stdio.h>
#include <stdlib.h>

// Define a structure for a dynamic array
struct Array
{
    int *A;     // Array pointer
    int size;   // Max size
    int length; // Current length
};

// Display array elements and properties
void display(struct Array a)
{
    printf("\nArray elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]); // Print elements
    }
    printf("\nFull array:\n");
    for (int i = 0; i < a.size; i++)
    {
        printf("%d ", a.A[i]); // Print all elements
    }

    printf("\nLength: %d", a.length); // Current length
    printf("\nSize: %d", a.size);     // Max size
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