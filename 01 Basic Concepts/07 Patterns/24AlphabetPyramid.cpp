// 24. Alphabet Pyramid Pattern
// Output:
//         A
//       B B B
//     C C C C C
//   D D D D D D D
// E E E E E E E E E
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "  ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << ch << " ";
        cout << endl;
        ch++;
    }
    return 0;
}
