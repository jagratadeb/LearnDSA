#include <bits/stdc++.h>
using namespace std;

bool check(int i, string &s)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - 1 - i])
        return false;
    return check(i + 1, s);
}

int main()
{
    string s = "racecar";
    cout << (check(0, s)) ? "Yes" : "No";
    return 0;
}