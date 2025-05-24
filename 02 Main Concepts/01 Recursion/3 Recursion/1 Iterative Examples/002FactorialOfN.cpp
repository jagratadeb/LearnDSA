#include <iostream>
#include <stdio.h>
using namespace std;

int fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = fact(n);
    cout << result << endl;
    return 0;
}