// Symmetric Matrix using 1D array (row-major storage)
#include <stdio.h>
#include <stdlib.h>

// Matrix structure for symmetric matrix
struct Matrix
{
    int *A; // 1D array to store elements
    int dimension; // Size of the matrix (n x n)
};

// Set value at (i, j) in symmetric matrix
void set(struct Matrix *m, int i, int j, int ele)
{
    // Store only lower triangle and mirror for upper
    if (i >= j)
        // row major for lower triangle
        m->A[(i * (i - 1)) / 2 + (j - 1)] = ele;
    else
        m->A[(j * (j - 1)) / 2 + (i - 1)] = ele;
}

// Get value at (i, j) in symmetric matrix
int get(struct Matrix m, int i, int j)
{
    if (i >= j)
        // row major formula for lower triangle
        return m.A[(i * (i - 1)) / 2 + (j - 1)];
    else
        return m.A[(j * (j - 1)) / 2 + (i - 1)];
}

// Display the full symmetric matrix
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
    m.A = (int *)malloc(m.dimension * (m.dimension + 1) / 2 * sizeof(int));
    // Example symmetric matrix (4x4):
    // 1 2 3 4
    // 2 5 6 7
    // 3 6 8 9
    // 4 7 9 10
    set(&m, 1, 1, 1); // diagonal
    set(&m, 1, 2, 2); 
    set(&m, 1, 3, 3); 
    set(&m, 1, 4, 4); 
    set(&m, 2, 2, 5); 
    set(&m, 2, 3, 6); 
    set(&m, 2, 4, 7); 
    set(&m, 3, 3, 8); // diagonal
    set(&m, 3, 4, 9); 
    set(&m, 4, 4, 10); // diagonal

    printf("\nPrinting the matrix:\n");
    display(m);
    return 0;
}
