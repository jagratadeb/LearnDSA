#include <iostream>
using namespace std;

int fib(int n) {
    int a = 0, b = 1, sum = 0;
    if(n == 0 || n == 1)
        return n;
    for(int i = 2; i <= n; i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Result:" << fib(n) << endl;
    return 0;
}