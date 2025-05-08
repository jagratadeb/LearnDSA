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

void max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i];
        }
    }
    printf("Maximum element in Array: %d\n", max);
}

void min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    printf("Minimum element in Array: %d\n", min);
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    display(arr.A, arr.size);

    max(arr);
    min(arr);

    return 0;
}