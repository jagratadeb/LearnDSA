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

// Function to find the maximum element in the array
int maxElement(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to find and print all pairs with sum K using a hash map
void findPairSum(int arr[], int size, int max, int K)
{
    int *H;
    H = (int *)malloc((max + 1) * sizeof(int)); // Allocate memory for hash map

    for (int i = 0; i <= max; i++)
    {
        H[i] = 0; // Initialize hash map to 0
    }

    for (int i = 0; i < size; i++)
    {
        H[arr[i]]++; // Count occurrences of each element
    }

    for (int i = 0; i < size; i++)
    {
        int indexForH = K - arr[i]; // Find the complement
        if (H[indexForH] == 1)
        {
            printf("%d + %d = %d\n", arr[i], indexForH, K); // Print the pair
            // Prevention of duplicates 
            H[arr[i]]++;
        }
    }
    printf("\n");
    free(H);
}

int main()
{
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14}; // Input array
    int size = sizeof(arr) / sizeof(int);            // Size of array
    int max = maxElement(arr, size);                 // Find max element
    int K = 10;                                      // K = sum
    display(arr, size);                              // Display array
    findPairSum(arr, size, max, K);                  // Find and print pairs
    return 0;
}