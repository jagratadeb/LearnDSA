#include <iostream>
#include <cstring>
#include <algorithm> // for max()
using namespace std;

int L[100][100]; // DP table (global)

int LCS_Length(int n, int m, char A[], char B[])
{
    for (int i = 0; i <= m; i++)
        L[i][0] = 0;
    for (int j = 0; j <= n; j++)
        L[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

void LCS_String(int n, int m, char A[], char B[], char result[])
{
    int i = m, j = n;
    int index = L[m][n];
    result[index] = '\0';

    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            result[index - 1] = A[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
}

int main()
{
    char A[] = "AGGTAB";
    char B[] = "GXTXAYB";
    int n = strlen(A);
    int m = strlen(B);

    int length = LCS_Length(n, m, A, B);

    char result[100];
    LCS_String(n, m, A, B, result);

    cout << "Length of LCS = " << length << endl;
    cout << "LCS = " << result << endl;

    return 0;
}
