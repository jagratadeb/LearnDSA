#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element
    }
    printf("\n");
}

int binarySearch(struct Array arr, int key)
{
    int low = 0;
    int high = arr.length - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    display(arr);

    int key = 11;
    printf("%d found at index %d", key, binarySearch(arr, key));
    return 0;
}