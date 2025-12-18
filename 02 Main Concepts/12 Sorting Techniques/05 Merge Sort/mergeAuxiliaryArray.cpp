#include <iostream>
using namespace std;

void mergeTwoList(int arr[], int size);
void display(int arr[], int size);

int main()
{
    int arr[] = {2, 10, 18, 20, 23, 4, 9, 19, 25};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    mergeTwoList(arr, size);
    display(arr, size);

    return 0;
}

void mergeTwoList(int arr[], int size)
{
    int mid = -1;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            mid = i + 1;
            break;
        }
    }

    if (mid == -1)
        return;

    int *aux = new int[size];

    int i = 0;   // left subarray
    int j = mid; // right subarray
    int k = 0;

    while (i < mid && j < size)
    {
        if (arr[i] < arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }

    while (i < mid)
        aux[k++] = arr[i++];

    while (j < size)
        aux[k++] = arr[j++];

    for (i = 0; i < size; i++)
        arr[i] = aux[i];

    delete[] aux;
}

void display(int arr[], int size)
{
    cout << "\nPrinting the array...\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
