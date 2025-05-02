#include <iostream>
using namespace std;

void fun1(int x); // Function declaration for fun1

int main()
{
    cout << "Tail Recursion:" << endl;
    int x = 5;
    fun1(x);
    return 0;
}

void fun1(int x)
{
    if (x > 0) // Check if x is greater than 0
    {
        cout << x << endl; // Print the value of x
        fun1(x - 1);       // Recursively call fun1 with x - 1
    }
}
// 5
// 4
// 3
// 2
// 1