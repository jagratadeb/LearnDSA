#include <stdio.h>
#include <stdlib.h>

// Merges two sorted subarrays within a single array
void mergeSingleArray(int *arr, int size, int low, int mid, int high);

// Displays the array contents
void display(int *arr, int size);

int main()
{
    // Initial array with two sorted halves:
    // Left: 3, 7, 12, 16, 20 | Right: 5, 9, 13, 15, 19
    int arr[] = {3, 7, 12, 16, 20, 5, 9, 13, 15, 19};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size); // Show original array

    int mid = (0 + size - 1) / 2;                  // Midpoint for merging
    mergeSingleArray(arr, size, 0, mid, size - 1); // Merge two sorted halves

    display(arr, size); // Show merged array
    return 0;
}

void mergeSingleArray(int *arr, int size, int low, int mid, int high)
{
    // Allocate memory for temporary array
    int *auxiliaryArray = (int *)malloc(size * sizeof(int));

    // i traverses left half, j traverses right half, k builds merged array
    int i = low;
    int j = mid + 1;
    int k = 0;

    // Merge elements from both halves in sorted order
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            auxiliaryArray[k++] = arr[i++];
        else if (arr[i] > arr[j])
            auxiliaryArray[k++] = arr[j++];
        else // If equal, include one and skip duplicate
        {
            auxiliaryArray[k++] = arr[i++];
            j++;
        }
    }

    // Copy remaining elements from left half
    while (i <= mid)
        auxiliaryArray[k++] = arr[i++];

    // Copy remaining elements from right half
    while (j <= high)
        auxiliaryArray[k++] = arr[j++];

    // Copy merged result back to original array
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = auxiliaryArray[k];

    free(auxiliaryArray); // Free allocated memory
}

void display(int *arr, int size)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}