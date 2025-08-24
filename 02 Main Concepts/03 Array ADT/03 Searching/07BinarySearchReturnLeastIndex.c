#include <stdio.h>

// Function prototype
void display(int *arr, int size);
int binarySearch(int *arr, int size, int key);

void display(int *arr, int size)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int *arr, int size, int key)
{
    int low = 0;
    int high = size - 1;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
        {
            index = mid;
            high = mid - 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return index;
}

int main()
{
    int arr[] = {-12, 2, -8, -8, 2, 2, -8, -6, -1, 3, 6, 6, 66, 8, 11, 14, 17, 20, 22, 25, 29, 31};
    int size = sizeof(arr) / sizeof(int);
    int key;
    int index;
    printf("Enter key: ");
    scanf("%d", &key);
    display(arr, size);
    printf("Index of %d is %d\n", key, binarySearch(arr, size, key));
    return 0;
}