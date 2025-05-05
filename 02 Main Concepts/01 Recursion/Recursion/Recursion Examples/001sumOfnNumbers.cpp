#include <iostream>
using namespace std;

// Recursive function to calculate the sum of first n natural numbers
int sum(int n)
{
    // Base case: if n is 0, return 0
    if(n == 0)
        return 0;
    else
        // Recursive case: sum of n is sum of (n-1) plus n
        return sum(n-1) + n;
}

int main()
{
    // Initialize n with 4
    int n = 4;
    
    // Print the sum of first n natural numbers using recursion
    cout << "Sum of first "<< n <<" natural numbers using Recursion:" << endl;
    cout << sum(n);
    
    // Return 0 to indicate successful execution
    return 0;
}



