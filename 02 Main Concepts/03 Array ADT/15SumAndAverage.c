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

int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int avg(struct Array arr)
{
    return (float)sum(arr) / arr.length;
}

int sumRecursion(struct Array arr, int length)
{
    if (length < 0)
    {
        return 0;
    }
    else
    {
        return sumRecursion(arr, length - 1) + arr.A[length];
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};

    display(arr.A, arr.size);

    int sumResult = sum(arr);
    printf("\nSum = %d", sumResult);

    float avgResult = avg(arr);
    printf("\nAverage = %0.2f", avgResult);

    int sumRecursionResult = sumRecursion(arr, arr.length - 1);
    printf("\nSum (Recursive) = %d", sumRecursionResult);

    return 0;
}