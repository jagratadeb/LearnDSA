#include <stdio.h>

// Function to increment each element in the array by 1
void func(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] = arr[i] + 1;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Initialize an array with 5 elements

    // Print the original array elements
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    // Call the function to increment each element
    func(arr);
    printf("\n");

    // Print the modified array elements
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0; // Return 0 to indicate successful execution
}
