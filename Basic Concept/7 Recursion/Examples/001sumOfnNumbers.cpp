#include <iostream>
using namespace std;

int sum(int n)
{
    if(n == 0)
        return 0;
    else
        return sum(n-1) + n;
}

int main()
{
    int n = 4;
    cout << "Sum of first "<< n <<" natural numbers using Recursion:" << endl;
    cout << sum(n);
    return 0;
}



