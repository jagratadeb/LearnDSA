#include <iostream>
using namespace std;

// Function to calculate factorial of a number using recursion
int fact(int n)
{
    // Base case: factorial of 0 is 1
    if (n == 0)
        return 1;
    else
        // Recursive case: n * factorial of (n-1)
        return fact(n - 1) * n;
}

int main()
{
    int n = 5; // Number to calculate the factorial of
    cout << "Factorial of " << n << " using Recursion:" << endl;
    cout << fact(n); // Output the result of the factorial function
    return 0;
}