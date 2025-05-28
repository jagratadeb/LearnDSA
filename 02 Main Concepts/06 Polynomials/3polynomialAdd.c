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

void create(struct Polynomial *P)
{
    printf("Enter number of terms:\n");
    scanf("%d", &P->n);
    P->t = (struct Terms *)malloc(P->n * sizeof(struct Terms));

    printf("Enter polynomial terms:\n");
    for (int i = 0; i < P->n; i++)
    {
        printf("Enter term no. %d :\n", i + 1);
        scanf("%d %d", &P->t[i].coeff, &P->t[i].exp);
    }
}

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

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    struct Polynomial *p3;
    p3 = (struct Polynomial *)malloc(sizeof(struct Polynomial));

    p3->t = (struct Terms *)malloc((p1->n + p2->n) * sizeof(struct Terms));

    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
        {
            p3->t[k] = p1->t[i];
            k++;
            i++;
        }
        else if (p1->t[i].exp < p2->t[j].exp)
        {
            p3->t[k] = p2->t[j];
            k++;
            j++;
        }
        else
        {
            p3->t[k].exp = p1->t[i].exp;
            p3->t[k].coeff = p1->t[i].coeff + p2->t[j].coeff;
            k++;
            i++;
            j++;
        }
    }

    while (i < p1->n)
    {
        p3->t[k] = p1->t[i];
        k++;
        i++;
    }
    while (j < p2->n)
    {
        p3->t[k] = p2->t[j];
        k++;
        j++;
    }

    p3->n = k;
    return p3;
}

int main()
{
    struct Polynomial P1, P2, *P3;

    create(&P1);
    create(&P2);

    display(P1);
    display(P2);

    P3 = add(&P1, &P2);
    display(*P3);

    free(P1.t);
    free(P2.t);
    free(P3->t);
    return 0;
}
