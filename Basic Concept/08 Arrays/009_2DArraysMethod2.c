#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *A[3];

    for(int i = 0; i < 3; i++){
        A[i] =  (int *)malloc(4*sizeof(int));
    }
    // Instead of FOR LOOP this can be used but FOR LOOP is more convenient.
    // A[0] =  (int *)malloc(4*sizeof(int));
    // A[1] =  (int *)malloc(4*sizeof(int));
    // A[2] =  (int *)malloc(4*sizeof(int));

    // Initialize the 2D array with some values.
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            A[i][j] = i + j + 1;
        }
    }

    // Print the elements of the 2D array in a matrix format
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory for each row
    for(int i = 0; i < 3; i++){
        free(A[i]);
    }

    return 0;
}
