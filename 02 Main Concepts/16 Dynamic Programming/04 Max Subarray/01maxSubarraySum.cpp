#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<int> maxSubarraySum(int arr[], int size);

int main()
{
    int arr[] = {4, -5, 8, -2, -1, 7, -6};
    int size = sizeof(arr) / sizeof(int);

    vector<int> result = maxSubarraySum(arr, size);

    cout << "Max Sum: " << result[0] << endl;

    for (int i = result[1]; i <= result[2]; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

vector<int> maxSubarraySum(int arr[], int size)
{
    int maxSum = INT_MIN;
    int start = 0, end = 0;

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum > maxSum)
            {
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }
    return {maxSum, start, end};
}