#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10

struct Node
{
    int col, val;
    struct Node *next;
};

struct Row
{
    struct Node *next;
};

struct Node *createNode(int col, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Row *matrix[], int row, int col, int val)
{
    if (row >= MAX_ROWS)
        return;

    struct Node *newNode = createNode(col, val);
    if (!matrix[row])
    {
        matrix[row] = (struct Row *)malloc(sizeof(struct Row));
        matrix[row]->next = newNode;
    }
    else
    {
        struct Node *temp = matrix[row]->next, *prev = NULL;
        while (temp && temp->col < col)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev)
            prev->next = newNode;
        else
            matrix[row]->next = newNode;
        newNode->next = temp;
    }
}

void display(struct Row *matrix[])
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        struct Node *temp = matrix[i] ? matrix[i]->next : NULL;
        while (temp)
        {
            printf("Row: %d, Col: %d, Value: %d\n", i, temp->col, temp->val);
            temp = temp->next;
        }
    }
}

void freeMemory(struct Row *matrix[])
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        if (matrix[i])
        {
            struct Node *temp = matrix[i]->next;
            while (temp)
            {
                struct Node *delNode = temp;
                temp = temp->next;
                free(delNode);
            }
            free(matrix[i]);
        }
    }
}

int main()
{
    struct Row *matrix[MAX_ROWS] = {NULL};

    insert(matrix, 0, 2, 3);
    insert(matrix, 1, 0, 5);
    insert(matrix, 2, 1, 7);

    printf("Sparse Matrix Representation:\n");
    display(matrix);
    freeMemory(matrix);
    return 0;
}
