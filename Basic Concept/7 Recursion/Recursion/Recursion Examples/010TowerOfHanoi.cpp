#include <iostream>
#include <cmath>
using namespace std;

void TOH(int n,int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n-1,A,C,B);
        cout << "(" << A << "," << C << ")" << endl;
        TOH(n-1,B,A,C);
    }
}

int main()
{
    int n, stepCount;
    cout << "Enter number of disk: ";
    cin >> n;
    TOH(n,1,2,3);
    stepCount = pow(2,n) - 1;
    cout << "Total number of steps: " << stepCount << endl;
    return 0;
}