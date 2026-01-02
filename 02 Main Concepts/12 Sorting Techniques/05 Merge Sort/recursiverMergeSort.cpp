#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int low, int mid, int high)
{
    int size = high - low + 1;
    int *auxiliaryArray = new int[size];

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            auxiliaryArray[k++] = arr[i++];
        }
        else if (arr[i] > arr[j])
        {
            auxiliaryArray[k++] = arr[j++];
        }
        else
        {
            auxiliaryArray[k++] = arr[i];
            j++;
            i++;
        }
    }

    while (i <= mid)
    {
        auxiliaryArray[k++] = arr[i++];
    }
    while (j <= high)
    {
        auxiliaryArray[k++] = arr[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = auxiliaryArray[k];

    delete[] auxiliaryArray;
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {8, 3, 7, 2, 6, 5, 9, 4, 1};
    int size = sizeof(arr) / sizeof(int);
    cout << "Display Array:\n";
    display(arr, size);
    mergeSort(arr, 0, size - 1);
    cout << "Display Sorted Array:\n";
    display(arr, size);
    return 0;
}