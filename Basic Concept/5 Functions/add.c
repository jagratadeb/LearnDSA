#include <stdio.h>

int add(int a, int b)
{
    int c;
    c = a + b;
    return (c);
}

int main()
{
    int x, y, z;
    printf("Enter 2 numbers:\n");
    scanf("%d %d", &x, &y);
    z = add(x, y);
    printf("Output:\n");
    printf("%d", z);
    return 0;
}
