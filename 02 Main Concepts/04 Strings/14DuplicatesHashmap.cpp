#include <iostream>
using namespace std;

void findDuplicate(char *string);

int main()
{
    char string[] = "This code works for both sorted and unsorted string, it can find duplication in lowercase, uppercase , digit and special characters.";
    cout << "Original String: " << string << endl;
    findDuplicate(string);
    return 0;
}

void findDuplicate(char *string)
{
    int length;
    for (length = 0; string[length] != '\0'; length++)
    {
    }

    // Use a hash array for all possible ASCII characters
    int H[256] = {0};
    for (int i = 0; i < length; i++)
    {
        // Converts character to its ASCII value using (unsigned char) to ensure positive indexing in H[]
        H[(unsigned char)string[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (H[i] > 1)
        {
            printf("Element %c appears %d times\n", i, H[i]);
        }
    }
}