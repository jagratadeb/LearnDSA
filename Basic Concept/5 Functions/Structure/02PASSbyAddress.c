#include <stdio.h>

// Define a struct named Rectangle
struct Rectangle
{
    int length;  // Length of the rectangle
    int breadth; // Breadth of the rectangle
};

// Function to change the length of the rectangle
int changeLength(struct Rectangle *p, int l)
{
    p->length = l; // Set the length of the rectangle
}

int main()
{
    // Initialize a struct Rectangle with length 10 and breadth 5
    struct Rectangle r = {10, 5};
    changeLength(&r, 20);                            // Change the length to 20
    printf("L = %d\nB = %d\n", r.length, r.breadth); // Print the new dimensions
    return 0;
}
