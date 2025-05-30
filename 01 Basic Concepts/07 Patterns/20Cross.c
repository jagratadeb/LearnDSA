// Pattern 20: Cross Pattern
// Example:
// *   *
//  * *
//   *
//  * *
// *   *

#include <stdio.h>
int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i || j == n - i + 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
