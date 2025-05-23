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
        m->A[i] = ele;
    }
}

int get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i];
    return 0;
}

void display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.dimension; i++)
    {
        for (j = 0; j < m.dimension; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
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

    set(&m, 0, 0, 5);
    set(&m, 1, 1, 10);
    set(&m, 2, 2, 15);
    set(&m, 3, 3, 20);
    set(&m, 4, 4, 25);

    printf("Element at (4,4): %d\n", get(m, 3, 3));
    printf("Element at (2,2): %d\n", get(m, 1, 1));
    printf("Element at (1,2): %d\n", get(m, 0, 1));
    printf("Element at (2,1): %d\n", get(m, 1, 0));

    display(m);
    return 0;
}
