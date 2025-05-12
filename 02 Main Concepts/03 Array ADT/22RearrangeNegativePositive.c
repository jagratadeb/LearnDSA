#include <stdio.h>

// Structure to represent an array with its size and current length
struct Array
{
    int A[10];  // Array to hold elements
    int size;   // Maximum size of the array
    int length; // Current number of elements in the array
};

// Function prototype
void display(struct Array arr);
void swap(int *i, int *j);
void rearrange(struct Array *arr);

int main()
{
    // Initialize an array with both negative and positive numbers
    struct Array arr = {{-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 10, 10};

    printf("Show Original Array:\n");
    display(arr); // Display the original array

    printf("Array after Rearranging:\n");
    rearrange(&arr); // Rearrange the array
    display(arr);    // Display the rearranged array

    return 0; // End of the program
}

// Function to display the elements of the array
void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to swap two integers
void swap(int *i, int *j)
{
    int temp;
    temp = *i; // Store the value of i in temp
    *i = *j;   // Assign the value of j to i
    *j = temp; // Assign the value of temp to j
}

// Function to rearrange the array so that negative numbers come before positive numbers
void rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;

    // Use two pointers to rearrange the array
    while (i < j)
    {
        // Increment i until a positive number is found
        while (arr->A[i] < 0)
        {
            i++;
        };
        // Decrement j until a negative number is found
        while (arr->A[j] >= 0)
        {
            j--;
        };
        // Swap the positive and negative numbers
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}