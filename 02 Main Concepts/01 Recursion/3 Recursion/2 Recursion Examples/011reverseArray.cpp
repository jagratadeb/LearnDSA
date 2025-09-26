#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverse(arr, l + 1, r - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int l = 0;
    int r = arr.size() - 1;
    print(arr);
    reverse(arr, l, r);
    print(arr);
}