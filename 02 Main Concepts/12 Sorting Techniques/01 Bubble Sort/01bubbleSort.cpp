#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    cout << "Printing the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size)
{
    cout << "\nBubble Sort .....\n";
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 6, 3, 9, 10, 100, 99, 95, 45};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}