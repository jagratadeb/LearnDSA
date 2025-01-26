#include <iostream>
using namespace std;

void fun2(int x); // Function declaration for fun2

int main()
{
    int x = 5;
    fun2(x);
    return 0;
}

void fun2(int x)
{
    if (x > 0) // Check if x is greater than 0
    {
        fun2(x - 1); // Recursively call fun2 with x - 1
        cout << x << endl; // Print the value of x
    }
}
// 1
// 2
// 3
// 4
// 5
