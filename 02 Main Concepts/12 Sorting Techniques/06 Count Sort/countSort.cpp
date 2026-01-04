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

int findMax(int arr[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int size)
{
    int i, j;
    int max = findMax(arr, size);
    int *tempArray = new int[max + 1];
    for (i = 0; i < max + 1; i++)
        tempArray[i] = 0;

    for (i = 0; i < size; i++)
        tempArray[arr[i]]++;

    i = 0; // temporary array
    j = 0; // main array

    while (i < max + 1)
    {
        if (tempArray[i] > 0)
        {
            arr[j++] = i;
            tempArray[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    int size = sizeof(arr) / sizeof(int);
    cout << "Display Array:\n";
    display(arr, size);
    countSort(arr, size);
    cout << "Display Sorted Array:\n";
    display(arr, size);

    return 0;
}