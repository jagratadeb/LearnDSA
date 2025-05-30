// Pattern 18: Number Pyramid
// Example:
//   1
//  2 2
// 3 3 3

#include <stdio.h>
int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}
