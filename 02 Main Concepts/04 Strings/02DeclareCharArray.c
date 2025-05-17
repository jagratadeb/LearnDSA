#include <stdio.h>

void display(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Declaration
    int size = 0;

    char X[5];
    size = sizeof(X) / sizeof(char);
    display(X, size);

    // Declaration + Initialization
    char Y[5] = {'A', 'B', 'C', 'D', 'E'};
    size = sizeof(Y) / sizeof(char);
    display(Y,size);

    /* If the size is not mentioned, then the array will be
    sized automatically based on the number of elements in it.*/
    char Z[] = {'H', 'E', 'L', 'L', 'O'};
    size = sizeof(Z) / sizeof(char);
    display(Z,size);

    return 0;
}