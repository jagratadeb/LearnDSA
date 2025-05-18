#include <iostream>
using namespace std;

// Function to find duplicate characters in a sorted string
void findDuplicate(char *string)
{
    int length;
    for (length = 0; string[length] != '\0'; length++)
    {
    }
    char lastDuplicate = '\0';
    for (int i = 0; i < length - 1; i++)
    {
        if (string[i] == string[i + 1] && lastDuplicate != string[i])

        {
            lastDuplicate = string[i];
            cout << "Duplicate Character: " << string[i] << endl;
        }
    }
}

int main()
{
    char str[] = "PROGRAMMING"; // Sorted input string
    findDuplicate(str);
    return 0;
}
