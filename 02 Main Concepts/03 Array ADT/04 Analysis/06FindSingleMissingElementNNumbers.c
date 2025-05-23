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

void findSingleMissing(int arr[], int size)
{
    int low = arr[0];
    int high = arr[size - 1];

    int difference = low - 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] - i != difference)
        {
            printf("Missing Element: %d\n", i + difference);
            break;
        }
    }
}

int main()
{
    int arr[11] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);

    findSingleMissing(arr, size);
    return 0;
}