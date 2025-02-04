#include <iostream>
using namespace std;

void fun(int n)
{
    // If n is greater than 0, print n and call fun(n - 1)
    if (n > 0)
    {
        fun(n - 1); // tail recursion
        cout << n << endl;
    }
}

int main()
{
    int n = 3;
    cout << "This is an example of Head Recursion" << endl;
    cout << "Output:" << endl;
    fun(n); // Call the function with n = 3

    return 0;
}
