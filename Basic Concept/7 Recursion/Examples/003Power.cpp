#include <iostream>
using namespace std;

// Function to calculate m raised to the power n
int pow(int m, int n)
{
    // Base case: any number raised to the power 0 is 1
    if (n == 0)
        return 1;
    // Recursive case: m^n = m * m^(n-1)
    else
        return pow(2, n - 1) * m;        
}

int main()
{
    int m = 5, n = 1;
    // Calculate m raised to the power n
    int result = pow(m, n);
    // Print the result
    cout << m << "^" << n << " = " << result << endl;
    return 0;
}