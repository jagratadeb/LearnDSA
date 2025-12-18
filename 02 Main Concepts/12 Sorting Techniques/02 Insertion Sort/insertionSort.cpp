#include <iostream>
using namespace std;

// Function prototypes
void insertionSort(int arr[], int size);
void display(int arr[], int size);

int main()
{
    // Initialize an array with some values
    int arr[] = {2, 3, 7, 4, 99, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    // Display the original array
    display(arr, size);

    // Sort the array using insertion sort
    insertionSort(arr, size);

    // Display the sorted array
    display(arr, size);

    return 0;
}

// Function to print the array elements
void display(int arr[], int size)
{
    cout << "\nPrinting the array...\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl;
}

// Function to perform insertion sort
void insertionSort(int arr[], int size)
{
    cout << "\nInsertion Sort...\n";
    // Start from the second element (index 1)
    for (int i = 1; i < size; i++)
    {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;    // Index of the previous element

        // Shift elements greater than 'key' one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // Place 'key' at its correct position
        arr[j + 1] = key;
    }
}
