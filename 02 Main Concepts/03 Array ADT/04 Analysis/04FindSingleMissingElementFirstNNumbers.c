#include <stdio.h>

void display(int arr[], int size)
{
    printf("\nArray:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findSingleMissing(int arr[], int size)
{
    int sum = 0;
    int n = arr[size - 1];
    int S = (n * (n + 1)) / 2;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return S - sum;
}

int main()
{
    int arr[11] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    printf("Missing Element: %d\n",findSingleMissing(arr, size));
    return 0;
}