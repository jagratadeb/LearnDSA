// 23. Spiral Number Pattern
// Output:
//  1  2  3  4  5
// 16 17 18 19  6
// 15 24 25 20  7
// 14 23 22 21  8
// 13 12 11 10  9
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int arr[5][5];
    int val = 1, minRow = 0, maxRow = n - 1, minCol = 0, maxCol = n - 1;
    while (val <= n * n)
    {
        for (int i = minCol; i <= maxCol; i++)
            arr[minRow][i] = val++;
        minRow++;
        for (int i = minRow; i <= maxRow; i++)
            arr[i][maxCol] = val++;
        maxCol--;
        for (int i = maxCol; i >= minCol; i--)
            arr[maxRow][i] = val++;
        maxRow--;
        for (int i = maxRow; i >= minRow; i--)
            arr[i][minCol] = val++;
        minCol++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
