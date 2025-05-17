#include <iostream>
using namespace std;

bool valid(char *string)
{
    int i;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (!((string[i] >= 'A' && string[i] <= 'Z') ||
              (string[i] >= 'a' && string[i] <= 'z') ||
              (string[i] >= '0' && string[i] <= '9')))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[] = "Ani?123";

    if (valid(str))
        cout << "Valid string (only letters and digits)." << endl;
    else
        cout << "Invalid string (contains special characters)." << endl;
    return 0;
}
