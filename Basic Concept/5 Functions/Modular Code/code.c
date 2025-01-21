#include <stdio.h>

// Function to calculate the area of a rectangle
int area(int length, int breadth)
{
    return length * breadth; // Return the product of length and breadth
}

// Function to calculate the perimeter of a rectangle
int perimeter(int length, int breadth)
{
    int p;
    p = 2 * (length + breadth); // Calculate perimeter using the formula
    return p;                   // Return the calculated perimeter
}

int main()
{
    int length = 0, breadth = 0, A = 0, P = 0; // Initialize variables for length, breadth, area, and perimeter

    // Prompt user for input
    printf("Enter the length and breadth of the rectangle:\n");
    scanf("%d %d", &length, &breadth); // Read user input for length and breadth

    // Calculate area
    A = area(length, breadth);
    // Calculate perimeter
    P = perimeter(length, breadth);

    // Print the calculated area and perimeter
    printf("Area: %d\nPerimeter: %d\n", A, P);

    return 0; // Return 0 to indicate successful execution
}

/*
Modular code breaks a program into separate, manageable, and reusable pieces called modules. Each module has a specific function, making the code easier to read, maintain, debug, and test. Benefits include reusability, maintainability, readability, collaboration, and independent testing. The area and perimeter functions in the above code demonstrate modularity.
*/
