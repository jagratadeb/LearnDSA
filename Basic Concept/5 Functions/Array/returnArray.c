#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for an array and input its elements
int *func(int size)
{
    int *p;
    p = (int *)malloc(size * sizeof(int)); // Allocate memory for 'size' integers
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &p[i]); // Input elements into the allocated array
    }
    return p; // Return the pointer to the allocated array
}

int main()
{
    int sz = 5; // Size of the array
    int *p;
    p = func(sz); // Call the function to allocate memory and input elements

    // Print the elements of the array
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0; // Return 0 to indicate successful execution
}
