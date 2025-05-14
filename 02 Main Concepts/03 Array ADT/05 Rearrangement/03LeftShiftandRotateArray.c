#include <stdio.h>

// Define a structure to represent an array
struct Array
{
    int A[5];
    int size;
};

// Function prototypes
void leftShift(struct Array *arr);
void leftRotate(struct Array *arr);
void display(struct Array arr);

int main()
{
    // Initialize the array with elements and size
    struct Array arr = {{1, 2, 3, 4, 5}, 5};

    // Display the original array
    printf("\nShow the original array:\n");
    display(arr);

    // Perform left shift operation and display the array
    printf("Show the array after left shift:\n");
    leftShift(&arr);
    display(arr);

    // Perform left rotate operation and display the array
    printf("Show the array after left rotate:\n");
    leftRotate(&arr);
    display(arr);

    return 0;
}

// Function to perform left shift operation on the array
void leftShift(struct Array *arr)
{
    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->size - 1] = 0;
}

// Function to perform left rotate operation on the array
void leftRotate(struct Array *arr)
{
    int ele = arr->A[0];
    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->size - 1] = ele;
}

// Function to display the elements of the array
void display(struct Array arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}