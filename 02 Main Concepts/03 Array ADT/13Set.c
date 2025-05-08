#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Display array elements
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]); // Print element
    }
    printf("\n");
}

void set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->size)
    {
        arr->A[index] = value;
        printf("\nset(A[%d]) = %d \n", index, arr->A[index]);
    }
    else
    {
        printf("\nERROR! Invalid Index.\n");
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    display(arr.A, arr.size);

    set(&arr, 8, 19);
    set(&arr, 9, 20);
    set(&arr, 10, 21);

    display(arr.A, arr.size);

    return 0;
}