#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void display(int arr[], int size)
{
    printf("Show Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find and print all pairs with sum K in a sorted array
void findPairSum(int arr[], int size, int K)
{
    int i = 0;        // Start pointer
    int j = size - 1; // End pointer

    while (i < j)
    {
        if (arr[i] + arr[j] == K) // If pair found
        {
            printf("%d + %d = %d\n", arr[i], arr[j], K); // Print the pair
            i++;                                         // Move start pointer forward
            j--;                                         // Move end pointer backward
        }
        else if (arr[i] + arr[j] < K) // If sum is less than K
        {
            i++; // Move start pointer forward
        }
        else // If sum is greater than K
        {
            j--; // Move end pointer backward
        }
    }
}

int main()
{
    int arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14}; // Input sorted array
    int size = sizeof(arr) / sizeof(int);            // Size of array
    int K = 10;                                      // K = sum
    display(arr, size);                              // Display array
    findPairSum(arr, size, K);                       // Find and print pairs
    return 0;
}