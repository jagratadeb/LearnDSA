#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    int result;
    result = nCr(5, 2);
    cout << result << endl;
    return 0;
}