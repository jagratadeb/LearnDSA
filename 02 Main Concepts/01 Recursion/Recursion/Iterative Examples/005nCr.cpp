#include <iostream>
using namespace std;

int fact(int n)
{
    int f = 1;
    if(n == 0 || n == 1)
        return f;
    for(int i = 2; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

int nCr(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/(t2*t3);
}

int main()
{
    int n, r, result;
    cout << "Value of n: ";
    cin >> n;
    cout << "Value of r: ";
    cin >> r;
    result = nCr(n,r);
    cout << endl <<"Result = " << result << endl;
}