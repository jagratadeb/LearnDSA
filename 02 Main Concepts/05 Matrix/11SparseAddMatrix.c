#include <stdio.h>

void inputSparseMatrix(int matrix[][3], int size)
{
    printf("Enter row, column, and value for each non-zero element:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }
}

void displaySparseMatrix(int matrix[][3], int size)
{
    printf("R  C  V\n");
    printf("-------\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  %d  %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

void addSparseMatrices(int mat1[][3], int size1, int mat2[][3], int size2, int result[][3], int *sizeResult)
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (mat1[i][0] < mat2[j][0])
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
        }
        else if (mat1[i][0] > mat2[j][0])
        {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
        }
        else if (mat1[i][1] < mat2[j][1])
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
        }
        else if (mat1[i][1] > mat2[j][1])
        {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
        }
        else
        { // Same row and column, so we add values
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }

    while (j < size2)
    {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
    }

    *sizeResult = k;
}

int main()
{
    int size1, size2, sizeResult;

    printf("Enter the number of non-zero elements in matrix 1:\n");
    scanf("%d", &size1);
    int mat1[size1][3];
    inputSparseMatrix(mat1, size1);

    printf("Enter the number of non-zero elements in matrix 2:\n");
    scanf("%d", &size2);
    int mat2[size2][3];
    inputSparseMatrix(mat2, size2);

    int result[size1 + size2][3];

    addSparseMatrices(mat1, size1, mat2, size2, result, &sizeResult);

    printf("\nSparse Matrix 1:\n");
    displaySparseMatrix(mat1, size1);

    printf("\nSparse Matrix 2:\n");
    displaySparseMatrix(mat2, size2);

    printf("\nResultant Sparse Matrix (Addition Result):\n");
    displaySparseMatrix(result, sizeResult);

    return 0;
}
