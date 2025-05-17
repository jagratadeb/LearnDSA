#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char string[] = "Print and count the VOWELS";
    int i;
    int vowelCount = 0;
    int consonantCount = 0;

    cout << "The vowels are:\n";
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 'A' || string[i] == 'a' || string[i] == 'E' || string[i] == 'e' || string[i] == 'I' || string[i] == 'i' || string[i] == 'O' || string[i] == 'o' || string[i] == 'U' || string[i] == 'u')
        {
            vowelCount++;
            cout << string[i] << " ";
        }
        else if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z'))
        {
            consonantCount++;
        }
    }
    cout << "\nVowel Count = " << vowelCount << endl;
    cout << "Consonant Count = " << consonantCount << endl;

    cout << "\nThe String:";
    cout << "\n" << string;
    printf("\n");
    return 0;
}