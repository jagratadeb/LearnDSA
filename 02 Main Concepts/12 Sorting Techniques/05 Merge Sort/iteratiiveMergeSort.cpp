#include <iostream>
using namespace std;

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100]; // temporary array

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= h)
        B[k++] = A[j++];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void iMergeSort(int A[], int n)
{
    int p, i, l, mid, h;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
    // If n is not a power of 2
    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main()
{
    int A[] = {11, 5, 7, 2, 6, 9, 4};
    int n = sizeof(A) / sizeof(A[0]);

    iMergeSort(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
