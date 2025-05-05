#include <iostream>
using namespace std;

int power(int m, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            m = m * m;
            n /= 2;
        }
        else
        {
            result = result * m;
            n--;
        }
    }
    return result;
}

int main()
{
    int m, n;
    cout << "Enter base (m): ";
    cin >> m;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << m << "^" << n << " = " << power(m, n) << endl;

    return 0;
}
