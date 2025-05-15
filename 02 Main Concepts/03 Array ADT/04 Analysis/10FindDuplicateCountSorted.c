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

void findDuplicate(int arr[], int size)
{
    int j;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j = i + 1;
            while (arr[j] == arr[i])
            {
                j++;
            }
            printf("%d is repeating %d times\n", arr[i], j - i);
            i = j - 1;
        }
    }
}

int main()
{
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    findDuplicate(arr, size);
    return 0;
}