#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // size of hash table

// Node structure for linked list
struct Node
{
    int data;
    struct Node *next;
};

// Hash table (array of pointers to linked lists)
struct Node *hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Insert into hash table
void insert(int key)
{
    int index = hashFunction(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index]; // insert at beginning
    hashTable[index] = newNode;
}

// Search in hash table
int search(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->data == key)
            return 1; // found
        temp = temp->next;
    }
    return 0; // not found
}

// Display hash table
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Bucket %d: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    // Insert elements
    insert(15);
    insert(25);
    insert(35);
    insert(20);
    insert(30);
    insert(41);
    insert(42);
    insert(43);
    insert(44);

    // Display hash table
    display();

    // Search for elements
    int key = 25;
    if (search(key))
        printf("Element %d found in hash table.\n", key);
    else
        printf("Element %d not found.\n", key);

    return 0;
}
