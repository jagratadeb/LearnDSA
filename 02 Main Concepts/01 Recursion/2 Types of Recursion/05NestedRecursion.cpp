#include <iostream>
using namespace std;

int fun(int n);

int main()
{
    cout << "Nested Recursion:" << endl;
    cout << fun(95);
    return 0;
}


int fun(int n)
{
    if (n > 100)
        return n-10;
    else
        return fun(fun(n+11));
}
