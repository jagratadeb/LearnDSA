// lesser number of multiplications

#include <iostream>
using namespace std;

// Function to calculate m raised to the power n
int pow(int m, int n)
{
    // Base case: any number raised to the power 0 is 1
    if (n == 0)
        return 1;
    // If n is even, use the property (m^2)^(n/2) = m^n
    if (n % 2 == 0)
        return pow(m * m, n / 2);
    // If n is odd, use the property m*(m^2)^((n-1)/2) = m^n
    else
        return pow(m * m, (n - 1) / 2) * m;
}

int main()
{
    int m = 2, n = 9;
    // Calculate m raised to the power n
    int result = pow(m, n);
    // Print the result
    cout << m << "^" << n << " = " << result << endl;
    return 0;
}