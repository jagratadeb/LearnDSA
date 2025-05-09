#include <stdio.h>

struct Array
{
    int A[5];
    int size;
};

void leftShift(struct Array *arr)
{
    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->size - 1] = 0;
}

void leftRotate(struct Array *arr)
{
    int ele = arr->A[0];
    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->size - 1] = ele;
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

    printf("Show the array after left shift:\n");
    leftShift(&arr);
    display(arr);

    printf("Show the array after left rotate:\n");
    leftRotate(&arr);
    display(arr);

    return 0;
}