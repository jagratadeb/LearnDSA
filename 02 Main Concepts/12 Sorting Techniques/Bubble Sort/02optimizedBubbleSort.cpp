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
    int flag = 0;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << "\nArray is already sorted." << endl;
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}