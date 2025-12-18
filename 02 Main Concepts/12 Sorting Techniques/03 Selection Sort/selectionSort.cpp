#include <iostream>
using namespace std;

// Function prototypes
void selectionSort(int arr[], int size);
void display(int arr[], int size);

int main()
{
    int arr[] = {2, 3, 7, 4, 99, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // array length

    display(arr, size);       // show original
    selectionSort(arr, size); // sort array
    display(arr, size);       // show sorted

    return 0;
}

// print array
void display(int arr[], int size)
{
    cout << "\nPrinting the array...\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// selection sort
void selectionSort(int arr[], int size)
{
    cout << "\nSelection Sort...\n";
    int i, j, k;
    for (i = 0; i < size - 1; i++) // outer loop
    {
        for (j = k = i; j < size; j++) // find min index
            if (arr[j] < arr[k])
                k = j;

        swap(arr[i], arr[k]); // place min at front
    }
}
