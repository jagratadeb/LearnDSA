#include <stdio.h>
int main()
{
    // Declare a 2D array with 3 rows and 4 columns
    int A[3][4];

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

    return 0;
}