#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int dimension;
};

void set(struct Matrix *m, int i, int j, int ele)
{
    if (i >= j)
    { 
        // Row Major Formula
        m->A[(i * (i - 1)) / 2 + (j - 1)] = ele;
    }
}

int get(struct Matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.A[(i * (i - 1)) / 2 + (j - 1)];
    }
    return 0;
}

void display(struct Matrix m)
{
    for (int i = 1; i <= m.dimension; i++)
    {
        for (int j = 1; j <= m.dimension; j++)
        {
            if (i >= j)
                printf("%d ", m.A[(i * (i - 1)) / 2 + (j - 1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    int ele;

    printf("Enter Dimension:");
    scanf("%d", &m.dimension);
    m.A = (int *)malloc(m.dimension * (m.dimension + 1) / 2 * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 1; i <= m.dimension; i++)
    {
        for (int j = 1; j <= m.dimension; j++)
        {
            scanf("%d", &ele);
            set(&m, i, j, ele);
        }
    }

    printf("\nPrinting the matrix:\n");
    display(m);
    return 0;
}
