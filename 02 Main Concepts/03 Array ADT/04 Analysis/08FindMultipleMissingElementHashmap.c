#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size)
{
    printf("\nArray:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

void findMissing(int arr[], int size, int high, int low)
{
    int *H;
    H = (int *)malloc((high + 1) * sizeof(int));
    for (int i = 0; i <= high; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        H[arr[i]]++;
    }
    for (int i = low; i <= high; i++)
    {
        if (H[i] == 0)
        {
            printf("Missing Element: %d\n", i);
        }
    }
    free(H);
}

int main()
{
    int arr[10] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int size = sizeof(arr) / sizeof(int);
    int minElement = min(arr, size);
    int maxElement = max(arr, size);
    display(arr, size);
    findMissing(arr, size, maxElement, minElement);
    return 0;
}