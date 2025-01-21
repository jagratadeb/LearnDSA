#include <stdio.h>

// Define a struct named Test
struct Test
{
    int arr[5]; // Array of 5 integers
    int n;      // An integer variable
};

// Function to modify the struct Test
void fun(struct Test t1)
{
    t1.arr[0] = 100; // Set the first element of the array to 100
    t1.arr[1] = 99;  // Set the second element of the array to 99
}

// Function to print the struct Test
int print(struct Test Tprint)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", Tprint.arr[i]); // Print each element of the array
    }
    printf("\n%d\n", Tprint.n); // Print the integer variable
}

int main()
{
    // Initialize a struct Test with an array and an integer
    struct Test t = {{2, 4, 6, 8, 10}, 5};
    print(t); // Call the print function
    fun(t);   // Call the fun function
    return 0;
}
