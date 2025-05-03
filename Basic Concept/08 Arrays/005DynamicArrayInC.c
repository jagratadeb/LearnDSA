#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    int size;

    // Ask the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array dynamically
    p = (int*)malloc(size * sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &p[i]);
    }

    // Print the elements of the array
    printf("Elements of the dynamic array are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Deallocate the memory
    free(p);

    return 0;
}