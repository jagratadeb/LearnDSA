#include <iostream>
using namespace std;

void display(int arr[], int size);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int arr[] = {50, 95, 32, 54, 65, 88, 92, 5, 6, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);

    cout << "\nQuick Sort...\n";

    quickSort(arr, 0, size - 1);

    display(arr, size);

    return 0;
}

void display(int arr[], int size)
{
    cout << "\nPrinting the array...\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}