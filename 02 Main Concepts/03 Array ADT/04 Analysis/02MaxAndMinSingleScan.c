#include <stdio.h>

// Define the Array structure

// Display array elements
void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]); // Print each element
    }
    printf("\n");
}

void maxMin(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Max = %d\nMin = %d\n", max, min);
}

int main()
{
    int arr[10] = {5, 3, 8, 9, 6, 2, 10, 7, -1, 4}; // Initialize array
    int size = sizeof(arr) / sizeof(int);
    display(arr, size); // Display array elements
    maxMin(arr, size);  // Find and display the minimum element

    return 0;
}
