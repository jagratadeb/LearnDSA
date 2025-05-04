#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array a)
{
    printf("\nPrinting the array:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
    printf("\nPrinting the array entire:\n");
    for (int i = 0; i < a.size; i++)
    {
        printf("%d ", a.A[i]);
    }

    printf("\nLength of the array: %d", a.length);
    printf("\nSize of the array: %d", a.size);
}

int main()
{
    struct Array arr;
    printf("Enter size of the array:\n");
    scanf("%d", &arr.size); // 10

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0; // 5

    printf("Enter number of elements:");
    int n; // 5
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;

    display(arr);
    return 0;
}