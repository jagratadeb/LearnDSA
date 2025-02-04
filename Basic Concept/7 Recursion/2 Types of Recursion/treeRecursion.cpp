#include <iostream>  // Include the standard input-output stream library
using namespace std; // Use the standard namespace

// Function definition for 'fun' which performs tree recursion
void fun(int n)
{
    if (n > 0) // Base case: when n is greater than 0
    {
        cout << n;  // Print the current value of n
        fun(n - 1); // Recursive call to 'fun' with n-1
        fun(n - 1); // Another recursive call to 'fun' with n-1
    }
}

int main()
{
    int n = 3;                                                // Initialize n with a value of 3
    fun(n);                                                   // Call the 'fun' function with n
    cout << "\nThis is an example of Tree Recursion" << endl; // Print a message
    cout << "Output:" << endl;                                // Print a label for the output
    return 0;                                                 // End of the main function
}

// Output: 3211211
