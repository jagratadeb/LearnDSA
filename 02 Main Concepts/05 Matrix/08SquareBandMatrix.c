#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int *A;
    int dimension;
    int bandwidth;
};

void set(struct Matrix *m, int i, int j, int ele) {
    if (abs(i - j) <= m->bandwidth)
        m->A[(i - 1) * (2 * m->bandwidth + 1) + (j - i + m->bandwidth)] = ele;
}

int get(struct Matrix m, int i, int j) {
    if (abs(i - j) <= m.bandwidth)
        return m.A[(i - 1) * (2 * m.bandwidth + 1) + (j - i + m.bandwidth)];
    return 0;
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
    m.dimension = 5; // Example: 5x5 band matrix
    m.bandwidth = 2; // Example: bandwidth 2 (pentadiagonal)
    m.A = (int *)malloc(m.dimension * (2 * m.bandwidth + 1) * sizeof(int));
    // Example band matrix (5x5, bandwidth 2):
    // 1  2  3  0  0
    // 4  5  6  7  0
    // 8  9 10 11 12
    // 0 13 14 15 16
    // 0  0 17 18 19
    set(&m, 1, 1, 1);   // main diagonal
    set(&m, 1, 2, 2);   // upper band 1
    set(&m, 1, 3, 3);   // upper band 2
    set(&m, 2, 1, 4);   // lower band 1
    set(&m, 2, 2, 5);   // main diagonal
    set(&m, 2, 3, 6);   // upper band 1
    set(&m, 2, 4, 7);   // upper band 2
    set(&m, 3, 1, 8);   // lower band 2
    set(&m, 3, 2, 9);   // lower band 1
    set(&m, 3, 3, 10);  // main diagonal
    set(&m, 3, 4, 11);  // upper band 1
    set(&m, 3, 5, 12);  // upper band 2
    set(&m, 4, 2, 13);  // lower band 2
    set(&m, 4, 3, 14);  // lower band 1
    set(&m, 4, 4, 15);  // main diagonal
    set(&m, 4, 5, 16);  // upper band 1
    set(&m, 5, 3, 17);  // lower band 2
    set(&m, 5, 4, 18);  // lower band 1
    set(&m, 5, 5, 19);  // main diagonal

    printf("\nPrinting the matrix:\n");
    display(m);
    free(m.A); // free allocated memory
    return 0;
}
