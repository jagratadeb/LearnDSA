#include <stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};
void display(struct Array a)
{
    printf("\nPrinting the array:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
    printf("\nPrinting the array entire:\n");
    for (int i = 0; i < a.size; i++)
    {
        printf("%d ", a.A[i]);
    }

    printf("\nLength of the array: %d", a.length);
    printf("\nSize of the array: %d", a.size);
    printf("\nSize of the array (in Bytes): %d bytes", sizeof(int) * a.size);
}
int main()
{
    struct Array arr = {{1,2,3,4,5},20,5};

    display(arr);

    return 0;
}