#include <stdio.h>

struct Pair
{
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high)
{
    struct Pair result, left, right;
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }

    struct Pair result = findMinMax(arr, 0, n - 1);
    printf("Minimum Element: %d\n", result.min);
    printf("Maximum Element: %d\n", result.max);

    return 0;
}