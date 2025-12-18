#include <iostream>
using namespace std;

void mergeTwoList(int arr1[], int arr2[], int *arr3, int m, int n);

int main()
{
    int arr1[] = {2, 3, 10, 18, 20, 23};
    int m = sizeof(arr1) / sizeof(int);

    int arr2[] = {3, 4, 9, 19, 25};
    int n = sizeof(arr2) / sizeof(int);

    int *arr3 = new int[m + n];

    mergeTwoList(arr1, arr2, arr3, m, n);

    for (int i = 0; i < (m + n); i++)
    {
        cout << arr3[i] << " ";
    }
    delete[] arr3;
    return 0;
}

void mergeTwoList(int arr1[], int arr2[], int *arr3, int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[k++] = arr2[j++];
        }
        else
        {
            arr3[k++] = arr1[i++];
            arr3[k++] = arr1[j++];
        }
    }
    for (; i < m; i++)
    {
        arr3[k++] = arr1[i];
    }
    for (; j < n; j++)
    {
        arr3[k++] = arr2[j];
    }
}