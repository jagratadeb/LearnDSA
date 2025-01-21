#include <stdio.h>

int main()
{
    int length = 0, breadth = 0, area = 0, perimeter = 0;

    // Prompt user for the length and breadth of the rectangle
    printf("Enter the length and breadth of the rectangle:\n");
    scanf("%d %d", &length, &breadth);

    // Calculate area and perimeter of the rectangle
    area = length * breadth;
    perimeter = 2 * (length + breadth);

    // Print the area and perimeter of the rectangle
    printf("Area: %d\nPerimeter: %d\n", area, perimeter);

    return 0; // Return 0 to indicate successful execution
}

/* Monolithic code refers to a programming approach where the entire program is written as a single, large block of code without being broken down into smaller, reusable modules or functions.

In monolithic code, functionality is often entangled, making it harder to read, maintain, and debug.

This approach lacks the structure and clarity provided by modular code, where different functionalities are separated into distinct modules or functions.
*/
