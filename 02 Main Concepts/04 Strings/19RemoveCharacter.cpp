#include <iostream>
using namespace std;

char *removeChar(char *string, char ch);

int main()
{
    // Initialize the string
    char str[] = "character";
    char ch;
    cout << "Enter the character to delete:";
    // Take character input from user
    cin >> ch;

    // Call the function to remove the character
    char *result = removeChar(str, ch);
    cout << "New String: " << result << endl;
    return 0;
}

// Function to remove all occurrences of a character from a string
char *removeChar(char *string, char ch)
{
    int length;
    // Find the length of the string
    for (length = 0; string[length] != '\0'; length++)
    {
    }

    int i;
    int j = 0;
    // Traverse the string and copy characters except the one to be removed
    for (i = 0; i < length; i++)
    {
        if (string[i] != ch)
        {
            string[j] = string[i];
            j++;
        }
    }
    // Null-terminate the modified string
    string[j] = '\0';
    return string;
}