#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void evaluate(struct Polynomial P)
{
    int x = 0;
    int sum = 0;
    printf("\nEvaluate Polynomial:\n");
    printf("Enter the value of \"x\":\n");
    scanf("%d", &x);
    for (int i = 0; i < P.n; i++)
    {
        sum = sum + P.t[i].coeff * pow(x, P.t[i].exp);
    }
    printf("\nAnswer: %d", sum);
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
        printf("Enter term no. %d :\n", i + 1);
        scanf("%d %d", &P.t[i].coeff, &P.t[i].exp);
    }

    display(P);
    evaluate(P);

    free(P.t);
    return 0;
}
