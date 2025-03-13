#include <iostream>
using namespace std;

int main()
{
    int a = 10; // Declare an integer variable 'a' and initialize it with 10
    int &r = a; // Declare a reference variable 'r' that references 'a'

    // Print the value of 'a'
    cout << a << endl; // Output: 10

    // Print the value of 'r' (which is the same as the value of 'a')
    cout << r << endl; // Output: 10

    r++; // Increment the value of 'r' (and thus 'a') by 1

    a = 100; // Assign a new value to 'a'

    // Print the updated value of 'a'
    cout << a << endl; // Output: 100

    // Print the updated value of 'r' (which is now the same as 'a')
    cout << r << endl; // Output: 100

    return 0; // Return 0 to indicate successful execution
}
