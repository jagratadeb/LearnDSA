#include <stdio.h>

// Function to swap the values of two integers using pointers
void swap(int *x, int *y)
{
    int temp;
    temp = *x; // Store the value of x in temp
    *x = *y;   // Assign the value of y to x
    *y = temp; // Assign the value of temp (original x) to y
}

int main()
{
    int a, b;
    a = 10; // Initialize a with 10
    b = 20; // Initialize b with 20

    swap(&a, &b); // Call the swap function to swap the values of a and b

    // Print the swapped values of a and b
    printf("a = %d\nb = %d\n", a, b);

    return 0; // Return 0 to indicate successful execution
}
