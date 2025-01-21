#include <stdio.h>

// Function to print the elements of an array
void print(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]); // Print each element of the array
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Initialize an array with 5 elements

    // Call the print function to display the array elements
    print(arr);

    return 0; // Return 0 to indicate successful execution
}
