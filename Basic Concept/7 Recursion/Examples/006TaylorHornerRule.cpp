#include <iostream>
using namespace std;

// Function to calculate e^x using Horner's Rule
double e(double x, double n)
{
    static double s = 1; // Static variable to hold the series sum
    if (n == 0)
        return s; // Base case: if n is 0, return the sum
    s = 1 + x / n * s; // Update the sum using Horner's Rule
    return e(x, n - 1); // Recursive call with n-1
}

int main()
{
    double r = e(3, 10); // Calculate e^3 using 10 terms
    cout << r << endl; // Output the result
}