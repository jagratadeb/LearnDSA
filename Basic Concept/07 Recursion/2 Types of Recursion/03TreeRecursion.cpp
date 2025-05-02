#include <iostream>
using namespace std;

// Recursive function that prints the value of n and then calls itself twice with n-1
void fun(int n)
{
    // Check if n is greater than 0 to continue recursion
    if (n > 0)
    {
        // Print the current value of n
        cout << n << endl;

        // Recursive calls with n-1
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    cout << "Tree Recursion:" << endl;

    // Initialize n with 3
    int n = 3;

    // Call the recursive function with initial value of n
    fun(3);

    // Return 0 to indicate successful execution
    return 0;
}