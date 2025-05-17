#include <iostream>
using namespace std;

int main()
{
    char string[] = "PYTHON1";
    cout << "Original String: " << string << endl;
    int i, length;
    for (i = 0; string[i] != '\0'; i++)
    {
    }
    length = i;
    
    for (i = 0; i < (length) / 2; i++)
    {
        int temp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = temp;
    }
    cout << "Reversed String: " << string << endl;

    return 0;
}