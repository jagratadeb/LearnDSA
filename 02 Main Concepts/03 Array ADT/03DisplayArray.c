#include <stdio.h>
#include <stdlib.h>

// Display array elements
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]); // Print element
    }
    printf("\n");
}

int main()
{
    int *A; // Dynamic array pointer
    int size;

    printf("Enter size:\n");
    scanf("%d", &size); // Input size

    A = (int *)malloc(size * sizeof(int)); // Allocate memory

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &A[i]); // Input elements
    }

    display(A, size); // Display array

    free(A); // Free memory
}