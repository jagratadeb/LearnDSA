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
        bool sorted = true;

        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }

        if (sorted)
            break;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 10, 9, 8, 7, 6, 5};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}
