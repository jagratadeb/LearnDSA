#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int *A;
    int dimension;
};

void set(struct Matrix *m, int i, int j, int ele) {
    if (i <= j)
        m->A[j - i] = ele;
    else
        m->A[i - j] = ele;
}

int get(struct Matrix m, int i, int j) {
    if (i <= j)
        return m.A[j - i];
    else
        return m.A[i - j];
}

void display(struct Matrix m) {
    for (int i = 1; i <= m.dimension; i++) {
        for (int j = 1; j <= m.dimension; j++) {
            printf("%d ", get(m, i, j));
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    m.dimension = 4; // Example: 4x4 Toeplitz matrix
    m.A = (int *)malloc(m.dimension * sizeof(int));
    // Example Toeplitz matrix (4x4):
    // 1 2 3 4
    // 5 1 2 3
    // 6 5 1 2
    // 7 6 5 1
    set(&m, 1, 1, 1); // first row
    set(&m, 1, 2, 2);
    set(&m, 1, 3, 3);
    set(&m, 1, 4, 4);
    set(&m, 2, 1, 5); // first column (except [1,1])
    set(&m, 3, 1, 6);
    set(&m, 4, 1, 7);
    printf("\nPrinting the matrix:\n");
    display(m);
    free(m.A);
    return 0;
}
