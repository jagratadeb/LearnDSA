#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    int i;

    // Allocate memory in the heap for a smaller array
    p = (int *)malloc(5 * sizeof(int));

    // Initialize the smaller array
    for (i = 0; i < 5; i++)
    {
        p[i] = i + 1;
    }

    // Print the elements of the smaller array
    printf("Smaller Array:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }

    // Allocate memory in the heap for a larger array
    q = (int *)malloc(10 * sizeof(int));

    // Copy the contents of the smaller array to the larger array
    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // Free the memory allocated for the smaller array
    free(p);
    // Point p to the larger array and set q to NULL
    p = q;
    q = NULL;

    printf("\n");
    // Print the elements of the larger array
    printf("Larger Array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }

    free(p);

    return 0;
}