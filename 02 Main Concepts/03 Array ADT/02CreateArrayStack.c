#include <stdio.h>

// Define a structure to represent a static array
struct Array
{
    int A[20]; // Array with a fixed size of 20 elements
    int size; // Maximum size of the array
    int length; // Current number of elements in the array
};

// display function prototype
void display(struct Array a);

int main()
{
    // Initialize a static array with some elements
    struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};

    display(arr); // Display the array and its properties

    return 0;
}

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
    printf("\nSize of the array (in Bytes): %d bytes", sizeof(int) * a.size); // Print the size in bytes
}