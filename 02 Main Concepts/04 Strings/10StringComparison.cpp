#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char str1[] = "apple";
    char str2[] = "banana";
    int i = 0;
    int isSame = 1;

    // Compare characters until a mismatch is found or end of one string is reached
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            isSame = 0;
            break;
        }
        i++;
    }
    // After loop, check if both strings ended (are same length) and isSame is still 1
    if (isSame && str1[i] == '\0' && str2[i] == '\0')
    {
        printf("%s and %s are same!\n", str1, str2);
    }
    else
    {
        printf("%s and %s are not same!\n", str1, str2);
    }

    return 0;
}