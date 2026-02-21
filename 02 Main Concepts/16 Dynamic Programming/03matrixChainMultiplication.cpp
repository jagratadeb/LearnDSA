#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> m;
vector<int> p;

int mcm(int i, int j)
{
    if (i == j)
    {
        m[i][j] = 0;
        return 0;
    }
    if (m[i][j] != -1)
    {
        return m[i][j];
    }

    m[i][j] = INT_MAX;
    int cost = 0;
    for (int k = i; k < j; k++)
    {
        m[i][k] = mcm(i, k);
        m[k + 1][j] = mcm(k + 1, j);
        cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        m[i][j] = min(m[i][j], cost);
    }
    return m[i][j];
}

int main()
{
    p = {40, 20, 30, 10, 30};
    int n = static_cast<int>(p.size()) - 1;
    m.assign(n + 1, vector<int>(n + 1, -1));
    int result = mcm(1, n);
    cout << "Minimum number of multiplications: " << result << endl;
    return 0;
}