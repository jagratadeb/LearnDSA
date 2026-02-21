#include <iostream>
using namespace std;

#define MAXM 100
#define MAXN 100

int w[MAXN], p[MAXN];
int T[MAXN][MAXM];

int knap(int n, int m)
{
    if (n == 0 || m == 0)
        return T[n][m] = 0;

    if (T[n][m] != -1)
        return T[n][m];

    if (w[n] <= m)
    {
        int no = knap(n - 1, m);
        int yes = knap(n - 1, m - w[n]) + p[n];
        T[n][m] = (no > yes) ? no : yes;
    }
    else
    {
        T[n][m] = knap(n - 1, m);
    }

    return T[n][m];
}

int main()
{
    int n, m;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> m;

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    cout << "Enter profits of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            T[i][j] = -1;

    int maxProfit = knap(n, m);

    cout << "\nMaximum Profit = " << maxProfit << endl;

    return 0;
}
