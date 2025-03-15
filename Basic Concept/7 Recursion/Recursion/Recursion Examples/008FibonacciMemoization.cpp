#include <iostream>
using namespace std;

// Array to store Fibonacci numbers
int F[50];

// Function to calculate Fibonacci number using memoization
int fib(int n)
{
    if(n <= 1) // Base case
    {
        F[n] = n; // Store the result in the array
        return n;
    }
    else
    {
        // Check if the value is already computed
        if(F[n-2] == -1)
            F[n-2] = fib(n-2);
        if(F[n-1] == -1)
            F[n-1] = fib(n-1);
        return F[n-2] + F[n-1]; // Return the sum of the previous two Fibonacci numbers
    }
}

int main()
{
    // Initialize the array with -1
    for(int i = 0; i<50;i++)
    {
        F[i] = -1;
    }
    int r = fib(10); // Calculate the 10th Fibonacci number
    cout <<"Result:"<< r << endl;

    // Print the array
    cout << "Array:" << endl;
    for(int i = 0; i < 50; i++){
        cout << F[i] << " ";
    }
}

