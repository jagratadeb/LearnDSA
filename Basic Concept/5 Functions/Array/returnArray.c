#include <stdio.h>
#include <stdlib.h>

int * func(int size)
{
    int * p;
    p = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%d", &p[i]);
    }
    return p;
}

int main()
{
    int sz = 5;
    int * p;
    p = func(sz);
    for(int i = 0; i < sz; i++){
        printf("%d ", *(p+i));
    }

    return 0;
}