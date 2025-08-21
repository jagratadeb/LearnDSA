#include <iostream>
#include <cstring>

using namespace std;

bool areAnagrams(char A[], char B[]);

int main()
{
    char A[] = "listen";
    char B[] = "silent";

    if (areAnagrams(A, B))
    {
        cout << "YES, they are anagrams!" << endl;
    }
    else
    {
        cout << "NO, they are not anagrams!" << endl;
    }

    return 0;
}

bool areAnagrams(char A[], char B[])
{
    if (strlen(A) != strlen(B))
    {
        return false; // Different lengths, not an anagram
    }

    // Will work with H[128] but that will be limited only to (A-Z,a-z,0-9,!@#$%^&*())
    int H[256] = {0}; // ASCII character frequency array

    // count occurrences of characters in A
    for (int i = 0; A[i] != '\0'; i++)
    {
        H[(unsigned char)A[i]]++;
    }

    // Subtract occurrences of characters in B
    for (int i = 0; B[i] != '\0'; i++)
    {
        H[(unsigned char)B[i]]--;
    }

    // If all Hs are zero, it's an anagram
    for (int i = 0; i < 256; i++)
    {
        if (H[i] != 0)
        {
            return false;
        }
    }

    return true;
}