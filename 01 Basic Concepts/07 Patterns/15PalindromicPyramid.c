// Pattern 15: Palindromic Pyramid
// Example:
//   1
//  2 1 2
// 3 2 1 2 3

#include <stdio.h>
int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = i; j >= 1; j--)
            printf("%d", j);
        for (int j = 2; j <= i; j++)
            printf("%d", j);
        printf("\n");
    }
    return 0;
}
