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

void get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.size)
    {
        printf("\nget(%d) = %d \n", index, arr.A[index]);
    }
    else
    {
        printf("\nERROR! Invalid Index.\n");
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    display(arr.A, arr.size); // Display array
    get(arr, 8);              // Array, size (max capacity of array), index to get
    get(arr, 9);              // Array, size (max capacity of array), index to get
    get(arr, 10);             // Array, size (max capacity of array), index to get
    return 0;
}