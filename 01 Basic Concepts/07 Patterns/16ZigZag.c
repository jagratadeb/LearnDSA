// Pattern 16: Zig-Zag Pattern
// Example:
//   *   *   *
// *   *   *

#include <stdio.h>
int main()
{
    int n = 9;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
