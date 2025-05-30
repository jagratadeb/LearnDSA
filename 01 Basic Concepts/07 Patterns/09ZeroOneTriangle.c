// Pattern 09: 0-1 Triangle
// Example:
// 1
// 0 1
// 1 0 1

#include <stdio.h>
int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d", (i + j) % 2);
        printf("\n");
    }
    return 0;
}
