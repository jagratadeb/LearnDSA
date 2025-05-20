#include <iostream>
using namespace std;

char *removeChar(char *string, char ch)
{
    int length;
    for (length = 0; string[length] != '\0'; length++)
    {
    }

    int i;
    int j = 0;
    for (i = 0; i < length; i++)
    {
        if (string[i] != ch)
        {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';
    return string;
}

int main()
{
    char str[] = "character";
    char ch;
    cout << "Enter the character to delete:";
    cin >> ch;

    char *result = removeChar(str, ch);
    cout << "New String: " << result << endl;
    return 0;
}