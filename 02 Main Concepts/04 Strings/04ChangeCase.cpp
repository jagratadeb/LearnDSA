#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char string[] = "This Code Swaps UPPERCASE and lowercase Letters, 123!";
    int i;

    // Case conversion
    for (i = 0; string[i] != '\0'; i++)
    {
        // Convert into lower from upper
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
        // convert into upper from lower
        else if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }
    // print the newly converted array
    // for (int j = 0; j < i; j++)
    // {
    //     cout << string[j];
    // }
    cout << string;
    printf("\n");
    return 0;
}