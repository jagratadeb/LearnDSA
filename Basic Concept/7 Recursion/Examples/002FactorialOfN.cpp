#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int main()
{
    int n = 5;
    cout << "Sum of first " << n << " natural numbers using Recursion:" << endl;
    cout << fact(n);
    return 0;
}