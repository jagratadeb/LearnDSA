// 11. Pascal's Triangle
// Output:
//         1
//       1   1
//     1   2   1
//   1   3   3   1
// 1   4   6   4   1
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int line = 1; line <= n; line++)
    {
        int C = 1;
        for (int j = 1; j <= n - line; j++)
            cout << "  ";
        for (int i = 1; i <= line; i++)
        {
            cout << C << "   ";
            C = C * (line - i) / i;
        }
        cout << endl;
    }
    return 0;
}
