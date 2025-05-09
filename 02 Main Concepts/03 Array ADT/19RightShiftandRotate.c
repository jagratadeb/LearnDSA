#include <stdio.h>

struct Array
{
    int A[5];
    int size;
};

void rightShift(struct Array *arr)
{
    for (int i = arr->size - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

void rightRotate(struct Array *arr)
{
    int ele = arr->A[arr->size-1];
    for (int i = arr->size - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = ele;
}

void display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 5};

    printf("\nShow the original array:\n");
    display(arr);

    printf("Show the array after right shift:\n");
    rightShift(&arr);
    display(arr);

    printf("Show the array after right rotate:\n");
    rightRotate(&arr);
    display(arr);

    return 0;
}