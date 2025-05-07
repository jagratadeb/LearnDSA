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

int recursiveBinarySearch(int arr[], int l, int h, int key)
{
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            return recursiveBinarySearch(arr,l,mid-1,key);
        }
        else
        {
            return recursiveBinarySearch(arr,mid+1,h,key);
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    display(arr);

    int key = 1;
    printf("%d found at index %d", key, recursiveBinarySearch(arr.A, 0, arr.length, key));
    return 0;
}