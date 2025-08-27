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

void recursiveMergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        recursiveMergeSort(arr, low, mid);
        recursiveMergeSort(arr, mid + 1, high);
        mergeArray(arr, low, mid, high);
    }
}

int main()
{

    int arr[] = {8, 3, 7, 2, 6, 5, 9, 4, 1};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    recursiveMergeSort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}