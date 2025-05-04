#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **A;

    // Allocate memory for an array of pointers to int
    A = (int **)malloc(3 * sizeof(int *));

    // Allocate memory for each row in the 2D array
    for (int i = 0; i < 3; i++)
    {
        A[i] = (int *)malloc(4 * sizeof(int));
    }

    // Initialize the 2D array with some values
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A[i][j] = i + j + 1;
        }
    }

    // Print the elements of the 2D array in matrix format
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory for each row
    for (int i = 0; i < 3; i++)
    {
        free(A[i]);
    }

    // Free the memory allocated for the array of pointers
    free(A);

    return 0;
}