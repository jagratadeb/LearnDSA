#include <iostream>
using namespace std;

// Function to calculate the Taylor series
double e(int x, int n)
{
    static double p = 1, f = 1; // Static variables to hold the power and factorial values
    double r;

    if (n == 0)
        return 1; // Base case: if n is 0, return 1
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
    double r = e(8, 100); // Calculate the Taylor series for e^8 with 100 terms
    cout << r << endl; // Output the result
    return 0;
}