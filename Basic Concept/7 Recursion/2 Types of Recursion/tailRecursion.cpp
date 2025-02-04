#include <iostream>
using namespace std;

void fun(int n)
{
    // If n is greater than 0, print n and call fun(n - 1)
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1); // Tail recursion: The function calls itself as the last action in its code block
    }
}

int main()
{
    int n = 3;
    cout << "This is an example of Tail Recursion" << endl;
    cout << "Output:" << endl;
    fun(n); // Call the function with n = 3

    return 0;
}
