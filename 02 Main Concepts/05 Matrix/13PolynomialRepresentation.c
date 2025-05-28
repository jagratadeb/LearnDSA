#include <stdio.h>
#include <stdlib.h>

struct Terms
{
    int coeff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Terms *t;
};

void display(struct Polynomial P)
{
    printf("\nDisplay Polynomial:\n");
    for (int i = 0; i < P.n; i++)
    {
        printf("%dX^%d", P.t[i].coeff, P.t[i].exp);
        if (i != P.n - 1)
        {
            printf(" + ");
        }
    }
}

int main()
{
    struct Polynomial P;
    printf("Enter number of terms:\n");
    scanf("%d", &P.n);
    P.t = (struct Terms *)malloc(P.n * sizeof(struct Terms));
    printf("Enter polynomial terms:\n");
    for (int i = 0; i < P.n; i++)
    {
        printf("Enter term no. %d ", i + 1);
        scanf("%d %d", &P.t[i].coeff, &P.t[i].exp);
    }

    display(P);
    
    free(P.t);
    return 0;
}
