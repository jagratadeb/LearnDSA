#include <iostream>
#include <utility>
#include <stdio.h>

using namespace std;

// Array structure
struct Array
{
    int A[10];  // Array elements
    int size;   // Maximum capacity
    int length; // Current number of elements
};

// Function prototype
void display(struct Array arr);
int linearSearch(struct Array *arr, int key);

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10}; // Initialize array

    display(arr); // Show array

    int ele = 5; // Element to search

    printf("\n%d is located at index %d\n", ele, linearSearch(&arr, ele)); // Search and print result
    display(arr);                                                          // Show updated array

    printf("\n%d is located at index %d\n", ele, linearSearch(&arr, ele)); // Search and print result
    display(arr);                                                          // Show updated array

    printf("\n%d is located at index %d\n", ele, linearSearch(&arr, ele)); // Search and print result
    display(arr);                                                          // Show updated array

    return 0;
}

// Display all elements in the array
void display(struct Array arr)
{
    printf("\n\nDisplaying the array:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// Linear search with transposition
int linearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i]) // Key found
        {
            swap(arr->A[i], arr->A[i - 1]); // Move closer to front
            return i;                       // Return index
        }
    }
    return -1; // Key not found
}