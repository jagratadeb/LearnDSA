#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
int *mergeTwoArrays(int *arr1, int size1, int *arr2, int size2, int *mergedSize);

// Display function
void display(int *arr, int size);

int main()
{
    int arr1[] = {2, 6, 10, 14, 18};
    int arr2[] = {1, 5, 9, 13, 17, 20};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    int mergedSize;

    int *mergedArray = mergeTwoArrays(arr1, size1, arr2, size2, &mergedSize);

    display(mergedArray, mergedSize);

    free(mergedArray); // Clean up
    return 0;
}

int *mergeTwoArrays(int *arr1, int size1, int *arr2, int size2, int *mergedSize)
{
    *mergedSize = size1 + size2;
    int *merged = (int *)malloc((*mergedSize) * sizeof(int));

    int i = 0, j = 0, k = 0;

    // Merge both arrays in sorted order
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements from arr1
    while (i < size1)
        merged[k++] = arr1[i++];

    // Copy remaining elements from arr2
    while (j < size2)
        merged[k++] = arr2[j++];

    return merged;
}

void display(int *arr, int size)
{
    printf("Merged array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}