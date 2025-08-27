#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int size)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeArray(int *arr, int low, int mid, int high)
{
    int size = high - low + 1;
    int *auxiliaryArray = (int *)malloc(size * sizeof(int));

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            auxiliaryArray[k++] = arr[i++];
        else if (arr[i] > arr[j])
            auxiliaryArray[k++] = arr[j++];
        else
        {
            auxiliaryArray[k++] = arr[i++];
            j++;
        }
    }
    while (i <= mid)
        auxiliaryArray[k++] = arr[i++];

    while (j <= high)
        auxiliaryArray[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = auxiliaryArray[k];

    free(auxiliaryArray);
}

void iterativeMergeSort(int *arr, int n)
{
    int last_size = 0;
    for (int size = 1; size < n; size *= 2)
    {
        last_size = size;
        for (int low = 0; low < n - size; low += 2 * size)
        {
            int mid = low + size - 1;
            int high = (low + 2 * size - 1 < n) ? (low + 2 * size - 1) : (n - 1);
            mergeArray(arr, low, mid, high);
        }
    }

    if (2 * last_size < n)
    {
        mergeArray(arr, 0, 2 * last_size - 1, n - 1);
    }
}

int main()
{
    int arr[] = {8, 3, 7, 2, 6, 5, 9, 4, 1};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    iterativeMergeSort(arr, size);
    display(arr, size);
    return 0;
}
