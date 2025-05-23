#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int dimension;
};

void set(struct Matrix *m, int i, int j, int ele)
{
    if (abs(i - j) <= 1)
        m->A[(i - 1) * 3 + (j - i + 1)] = ele;
}

int get(struct Matrix m, int i, int j)
{
    if (abs(i - j) <= 1)
        return m.A[(i - 1) * 3 + (j - i + 1)];
    return 0;
}

void display(struct Matrix m)
{
    for (int i = 1; i <= m.dimension; i++)
    {
        for (int j = 1; j <= m.dimension; j++)
        {
            printf("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.dimension = 4;
    m.A = (int *)malloc(m.dimension * 3 * sizeof(int));
    // Example tridiagonal matrix (4x4):
    // 1 2 0 0
    // 3 4 5 0
    // 0 6 7 8
    // 0 0 9 10
    set(&m, 1, 1, 1); // main diagonal
    set(&m, 1, 2, 2); // superdiagonal
    set(&m, 2, 1, 3); // subdiagonal
    set(&m, 2, 2, 4); // main diagonal
    set(&m, 2, 3, 5); // superdiagonal
    set(&m, 3, 2, 6); // subdiagonal
    set(&m, 3, 3, 7); // main diagonal
    set(&m, 3, 4, 8); // superdiagonal
    set(&m, 4, 3, 9); // subdiagonal
    set(&m, 4, 4, 10); // main diagonal

    printf("\nPrinting the matrix:\n");
    display(m);
    return 0;
}
