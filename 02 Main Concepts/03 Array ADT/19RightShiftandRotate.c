#include <stdio.h>

// Define a structure to represent an array
struct Array
{
    int A[5];
    int size;
};

// Function prototypes
void rightShift(struct Array *arr);
void rightRotate(struct Array *arr);
void display(struct Array arr);

int main()
{
    // Initialize the array with elements and size
    struct Array arr = {{1, 2, 3, 4, 5}, 5};

    // Display the original array
    printf("\nShow the original array:\n");
    display(arr);

    // Perform right shift operation and display the array
    printf("Show the array after right shift:\n");
    rightShift(&arr);
    display(arr);

    // Perform right rotate operation and display the array
    printf("Show the array after right rotate:\n");
    rightRotate(&arr);
    display(arr);

    return 0;
}

// Function to perform right shift operation on the array
void rightShift(struct Array *arr)
{
    for (int i = arr->size - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

// Function to perform right rotate operation on the array
void rightRotate(struct Array *arr)
{
    int ele = arr->A[arr->size - 1];
    for (int i = arr->size - 1; i >= 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = ele;
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