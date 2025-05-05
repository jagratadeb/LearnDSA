#include <stdio.h>
#include <stdlib.h>

void display(int A[], int size)
{
    printf("Displaying the array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int *A;
    printf("Enter the array size:\n");
    int size;
    scanf("%d", &size);

    A = (int *)malloc(size * sizeof(int));

    printf("Enter the %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }

    display(A, size);

    free(A);
}