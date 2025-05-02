#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number
int fib(int n)
{
    if(n <= 1)
        return n; // Base case: return n if n is 0 or 1
    return fib(n-2) + fib(n-1); // Recursive call to calculate the sum of the two preceding numbers
}

int main()
{
    int r = fib(10); // Calculate the 10th Fibo nacci number
    cout << r <<endl; // Output the result
}