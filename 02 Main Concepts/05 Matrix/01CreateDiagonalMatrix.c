#include <stdio.h>

struct Matrix
{
    int A[10];
    int dimension;
};

void set(struct Matrix *m, int i, int j, int ele)
{
    if (i == j)
    {
        m->A[i - 1] = ele;
    }
}

int get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    return 0;
}

void display(struct Matrix m)
{
    int i, j;
    for (i = 1; i <= m.dimension; i++)
    {
        for (j = 1; j <= m.dimension; j++)
        {
            if (i == j)
                printf("%d ", m.A[i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.dimension = 5;

    set(&m, 1, 1, 5);
    set(&m, 2, 2, 10);
    set(&m, 3, 3, 15);
    set(&m, 4, 4, 20);
    set(&m, 5, 5, 25);

    printf("Element at (4,4): %d\n", get(m, 4, 4));
    printf("Element at (2,2): %d\n", get(m, 2, 2));
    printf("Element at (1,2): %d\n", get(m, 1, 2));
    printf("Element at (2,1): %d\n", get(m, 2, 1));

    display(m);
    return 0;
}
