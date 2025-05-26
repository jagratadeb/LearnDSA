#include <stdio.h>

int main()
{
    int m;
    int n;
    int i, j;
    printf("Enter the dimensions (m x n):\n");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    printf("Enter the elements:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int countZero = 0, countNonZero = 0;

    printf("\nThe Matrix is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nCounting zeroes and non zeroes...\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                countZero++;
            }
            else
            {
                countNonZero++;
            }
        }
    }

    printf("Zero Elements: %d\n", countZero);
    printf("Non Zero Elements: %d\n", countNonZero);

    printf("\nSparse or not?\n");
    if (countZero > countNonZero)
    {
        printf("It is a Sparse Matrix.\n\n");
        int s[countNonZero][3], k = 0;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (arr[i][j] != 0)
                {
                    s[k][0] = i + 1;
                    s[k][1] = j + 1;
                    s[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        printf("\nSparse Matrix:\n");
        printf("R  C  V\n");
        printf("-------\n");
        for (i = 0; i < countNonZero; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d  ", s[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("It is not a sparse matrix.");
    }
    return 0;
}