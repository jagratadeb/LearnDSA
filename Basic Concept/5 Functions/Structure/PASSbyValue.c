#include <stdio.h>

// Define a struct named Rectangle
struct Rectangle
{
    int length;  // Length of the rectangle
    int breadth; // Breadth of the rectangle
};

// Function to calculate the area of the rectangle
int area(struct Rectangle rr)
{
    return rr.length * rr.breadth; // Return the area (length * breadth)
}

int main()
{
    // Initialize a struct Rectangle with length 10 and breadth 5
    struct Rectangle r = {10, 5};
    printf("The area is: %d", area(r)); // Print the area of the rectangle
    return 0;
}
