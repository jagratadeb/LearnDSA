// Pattern 08: Floyd's Triangle
// Example:
// 1
// 2 3
// 4 5 6

#include <stdio.h>
int main()
{
    int n = 5, num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", num++);
        printf("\n");
    }
    return 0;
}
