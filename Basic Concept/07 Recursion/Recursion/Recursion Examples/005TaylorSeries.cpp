#include <iostream>
using namespace std;

// Function to calculate the Taylor series
double e(int x, int n)
{
    static double p = 1, f = 1; // Static variables to hold the power and factorial
    double r;

    if (n == 0)
        return 1; // Base case: e^x = 1 when n is 0
    else
    {
        r = e(x, n - 1); // Recursive call
        p = p * x; // Calculate power of x
        f = f * n; // Calculate factorial of n
        return r + p / f; // Return the sum of the series
    }
}

int main()
{
    double r = e(8, 100); // Calculate e^8 using 100 terms
    cout << r << endl; // Print the result
    return 0;
}