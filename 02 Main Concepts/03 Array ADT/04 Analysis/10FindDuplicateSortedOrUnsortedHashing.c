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

void findDuplicate(int arr[], int size, int max)
{
    int *H;
    H = (int *)malloc((max+1) * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        H[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        if (H[i] > 1)
        {
            printf("Element %d (x%d)\n", i, H[i]);
        }
    }
    free(H);
}

int main()
{
    int arr[10] = {3,6,8,8,10,12,15,15,15,20};
    int size = sizeof(arr) / sizeof(int);
    int maxElement = max(arr, size);
    display(arr, size);
    findDuplicate(arr, size, maxElement);
    return 0;
}