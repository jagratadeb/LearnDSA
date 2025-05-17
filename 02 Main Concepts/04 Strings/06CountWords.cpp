#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char string[] = "This code example is just for counting the words.";
    int i;
    int wordCount = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        // This condition for "if" will take care of white spaces
        if (string[i] == ' ' && string[i - 1] != ' ')
        {
            wordCount++;
        }
    }
    wordCount++;

    cout << "The string:\n";
    cout << string;
    cout << "\nWord Count:" << wordCount;
    return 0;
}