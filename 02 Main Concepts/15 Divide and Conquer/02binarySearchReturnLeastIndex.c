#include <stdio.h>

int DACRecursiveBinarySearch(int *arr, int low, int high, int key)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;

    if (key == arr[mid])
    {
        int leftIndex = DACRecursiveBinarySearch(arr, low, mid - 1, key);
        return (leftIndex != -1) ? leftIndex : mid;
    }

    else if (key < arr[mid])
        DACRecursiveBinarySearch(arr, low, mid - 1, key);
    else
        DACRecursiveBinarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[] = {-22, -16, -10, -6, 1, 6, 6, 6, 6, 6, 10, 15, 20, 22, 50, 70, 75, 80, 81};
    int size = sizeof(arr) / sizeof(int);
    printf("Enter the key: ");
    int key;
    scanf("%d", &key);
    printf("The index of %d is %d\n", key, DACRecursiveBinarySearch(arr, 0, size - 1, key));

    return 0;
}