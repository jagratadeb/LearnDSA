#include <stdio.h>

// Structure to represent an array with its size and current length
struct Array
{
    int A[20];  // Array to hold elements
    int size;   // Maximum size of the array
    int length; // Current number of elements in the array
};

// Function prototypes
void insertInSortedArray(struct Array arr[], int ele);
void display(struct Array arr);

int main()
{
    // Initialize an array with some sorted elements
    struct Array arr = {{2, 4, 6, 8, 10, 12, 16, 18, 20}, 20, 9};

    printf("Original Array:\n");
    display(arr); // Display the original array

    // Insert elements into the sorted array and display the result
    int ele = 14;
    printf("Array after insertion:\n");
    insertInSortedArray(&arr, ele);
    display(arr);

    int ele2 = 100;
    printf("Array after insertion:\n");
    insertInSortedArray(&arr, ele2);
    display(arr);

    int ele3 = 55;
    printf("Array after insertion:\n");
    insertInSortedArray(&arr, ele3);
    display(arr);

    int ele4 = 17;
    printf("Array after insertion:\n");
    insertInSortedArray(&arr, ele4);
    display(arr);

    return 0; // End of the program
}

void display(struct Array arr)
// Function to display the elements of the array
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to insert an element into a sorted array
void insertInSortedArray(struct Array arr[], int ele)
{
    int i = arr->length - 1; // Start from the last element
    // Shift elements to the right to make space for the new element
    while (arr->A[i] > ele)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    i++;             // Find the correct position for the new element
    arr->A[i] = ele; // Insert the new element
    arr->length++;   // Increase the length of the array
}