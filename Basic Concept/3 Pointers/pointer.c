#include <stdio.h>

int main()
{
    int a = 10;  // Declare an integer variable 'a' and initialize it with 10
    int *p = &a; // Declare a pointer variable 'p' and store the address of 'a' in it

    // Print the value of 'a'
    printf("Value of a: %d\n", a); // Output: 10

    // Print the address stored in 'p' (which is the address of 'a')
    printf("Value of p: %d\n", p); // Output: Address of 'a' (memory location)

    // Print the value pointed to by 'p' (which is the value of 'a')
    printf("Value of *p: %d\n", *p); // Output: 10

    return 0; // Return 0 to indicate successful execution
}
