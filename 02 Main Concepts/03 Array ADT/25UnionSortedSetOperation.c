#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Function prototype
void display(struct Array arr);
struct Array *unionSorted(struct Array *arr1, struct Array *arr2);

int main()
{
    struct Array arr1 = {{3, 4, 5, 6, 10}, 10, 5};
    struct Array arr2 = {{2, 4, 5, 7, 12}, 10, 5};
    struct Array *arr3;
    arr3 = unionSorted(&arr1, &arr2);

    printf("Display Array 1:\n");
    display(arr1);
    printf("Display Array 2:\n");
    display(arr2);
    printf("Sorted Union Array:\n");
    display(*arr3);

    free(arr3);
    return 0;
}

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]); // Print each element
    }
    printf("\n"); // Print a newline after displaying all elements
}

struct Array *unionSorted(struct Array *arr1, struct Array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));

    arr3->length = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j])
        {

            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}