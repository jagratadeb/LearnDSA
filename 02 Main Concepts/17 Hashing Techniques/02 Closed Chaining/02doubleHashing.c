#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Primary hash function
int hashFunction1(int key)
{
    return key % TABLE_SIZE;
}

// Secondary hash function (must be non-zero and relatively prime to TABLE_SIZE)
int hashFunction2(int key)
{
    return 7 - (key % 7); // example choice
}

// Insert using double hashing
void insert(int key)
{
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    int i = 0;

    while (i < TABLE_SIZE)
    {
        int newIndex = (index1 + i * index2) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY)
        {
            hashTable[newIndex] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full, cannot insert %d\n", key);
}

// Search using double hashing
int search(int key)
{
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    int i = 0;

    while (i < TABLE_SIZE)
    {
        int newIndex = (index1 + i * index2) % TABLE_SIZE;
        if (hashTable[newIndex] == key)
            return newIndex; // found
        if (hashTable[newIndex] == EMPTY)
            return -1; // not found
        i++;
    }
    return -1; // not found
}

// Display hash table
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != EMPTY)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: EMPTY\n", i);
    }
}

int main()
{
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;

    // Insert elements
    insert(15);
    insert(25);
    insert(35);
    insert(20);
    insert(30);
    insert(40);

    // Display table
    display();

    // Search for an element
    int key = 25;
    int pos = search(key);
    if (pos != -1)
        printf("\nElement %d found at index %d\n", key, pos);
    else
        printf("\nElement %d not found\n", key);

    return 0;
}
