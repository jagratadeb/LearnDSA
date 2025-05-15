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
    int count;
    for (int i = 0; i < size; i++)
    {
        count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    arr[j] = -1;
                    count++;
                }
            }
            if (count > 1)
            {
                printf("Duplicate Element: %d (x%d)\n", arr[i], count);
            }
        }
    }
}

int main()
{
    int arr[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    findDuplicate(arr, size);
    return 0;
}