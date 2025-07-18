#include <iostream>
using namespace std;

void permutation(char s[], int k);

int main()
{
    char string[] = "ABC";
    permutation(string, 0);
    return 0;
}

void permutation(char s[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;
    if (s[k] == '\0')
    {
        Res[k] = '\0';
        cout << Res << endl;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                permutation(s, k + 1);
                A[i] = 0;
            }
        }
    }
}