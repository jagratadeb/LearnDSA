#include <iostream>
#include <string.h>
using namespace std;

void permutation(char s[], int l, int h);

int main()
{
    char string[] = "ABC";
    int lastIndex = strlen(string) - 1;
    permutation(string, 0, lastIndex);

    return 0;
}

void permutation(char s[], int l, int h)
{
    int i;
    if (l == h)
    {
        cout << s << " ";
    }
    else
    {
        for (int i = 0; i <= h; i++)
        {
            swap(s[l], s[i]);
            permutation(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}