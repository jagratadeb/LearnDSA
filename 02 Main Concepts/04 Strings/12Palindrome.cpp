#include <iostream>
using namespace std;

char *reverse(char *string)
{
    int i;
    int j;
    int length;
    for (i = 0; string[i] != '\0'; i++)
    {
    }
    length = i;
    i = i - 1;
    char *reverse;
    reverse = new char[length + 1];
    for (j = 0; i >= 0; j++, i--)
    {
        reverse[j] = string[i];
    }
    reverse[j] = '\0';

    return reverse;
}

int compare(char *arr1, char *arr2)
{
    int isSame = 1;
    int i = 0;
    while (arr1[i] != '\0' && arr2[i] != '\0')
    {
        if (arr1[i] != arr2[i])
        {
            isSame = 0;
            break;
        }
        i++;
    }
    return isSame;
}

int main()
{
    char string[] = "PYTHON";
    cout << "Original String: " << string << endl;

    char *reversedString;
    reversedString = reverse(string);
    cout << "Reversed String: " << reversedString << endl;

    int isSame = compare(string, reversedString);

    if (isSame)
    {
        cout << "Yes, it is a palindrome." << endl;
    }
    else
    {
        cout << "No, it is not a palindrome." << endl;
    }

    return 0;
}