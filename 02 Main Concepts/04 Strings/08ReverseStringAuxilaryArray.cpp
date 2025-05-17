#include <iostream>
using namespace std;

int main()
{
    char string[] = "PYTHON";
    cout << "Original String: " << string << endl;
    int i;
    int j;
    for (i = 0; string[i] != '\0'; i++)
    {
    }
    char Reverse[i];
    i = i - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        Reverse[j] = string[i];
    }
    Reverse[j] = '\0';
    cout << "Reversed String: " << Reverse << endl;

    return 0;
}