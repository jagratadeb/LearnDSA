#include <stdio.h>

int main()
{
    char str1[] = "Painting";
    char str2[] = "Painting";
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
    else if (str1[i] > str2[i])
    {
        printf("%s is greater than %s.\n", str1, str2);
    }
    else
    {
        printf("%s is greater than %s.\n", str2, str1);
    }

    return 0;
}