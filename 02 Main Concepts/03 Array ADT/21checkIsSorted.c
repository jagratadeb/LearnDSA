#include <stdio.h>
#include <stdlib.h>

// Function to display the elements of the array
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // Print each element
    }
    printf("\n"); // Print a newline after displaying all elements
}

// Function to check if the array is sorted in ascending order
int isSorted(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // If any element is greater than the next, the array is not sorted
        if (arr[i] > arr[i + 1])
        {
            return 0; // Return 0 if not sorted
        }
    }
    return 1; // Return 1 if sorted
}

int main()
{
    int *arr;
    int size;

    // Input the size of the array
    printf("Enter the size of array:\n");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));

    // Input the elements of the array
    printf("Insert %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display the array
    printf("Show the Array:\n");
    display(arr, size);

    // Check if the array is sorted and display the result
    int result = isSorted(arr, size);
    if (result == 0)
    {
        printf("Array is not sorted!\n");
    }
    else
    {
        printf("Array is sorted.\n");
    }

    return 0; // End of the program
}