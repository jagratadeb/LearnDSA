#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i;

    // Allocate memory for an array of size 5
    arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array
    for (i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    // Print the original array
    printf("Original Array:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Increase the size of the array to 10
    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Initialize the new elements
    for (i = 5; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    // Print the resized array
    printf("Resized Array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory for the array
    free(arr);

    return 0;
}