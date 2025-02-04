#include <iostream>
using namespace std;

void fun(int n)
{
    // If n is greater than 0, call fun(n - 1) and print n
    if (n > 0)
    {
        fun(n - 1); // Head recursion: The function calls itself before executing any other statements
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
