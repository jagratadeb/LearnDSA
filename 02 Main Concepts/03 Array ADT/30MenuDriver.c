#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

// Function prototype for displaying the array
struct Array *createArray(struct Array *arr);
void display(struct Array a);
void append(struct Array *arr, int ele);
void insert(struct Array *arr, int index, int ele);
void delete(struct Array *arr, int index);
int search(struct Array arr, int key);

int main()
{
    struct Array *arr;
    printf("Creating an array....\n");
    arr = createArray(arr);
    int choice = 0;
    do
    {
        printf("\n\nMenu Driver\n");
        printf("1. Display\n");
        printf("2. Append\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("10. Exit\n");

        printf("\nEnter choice:\n");
        scanf("%d", &choice);

        int ele = 0;
        int index = 0;
        switch (choice)
        {
        case 1:
            display(*arr);
            break;
        case 2:
            printf("Enter element to append:");
            scanf("%d", &ele);
            append(arr, ele);
            break;
        case 3:
            printf("Enter element and index to insert:");
            scanf("%d", &ele);
            scanf("%d", &index);
            insert(arr, index, ele);
            break;
        case 4:
            printf("Enter index to delete:");
            scanf("%d", &index);
            delete(arr, index);
            break;
        case 5:
            printf("Enter element to search:\n");
            scanf("%d", &ele);
            printf("%d is available at index %d", ele, search(*arr, ele));
            break;
        case 6:
            printf("Exit.");
            break;
        default:
            printf("Invalid Option.");
            break;
        }
    } while (choice < 6);

    free(arr);

    return 0; // End of the program
}

struct Array *createArray(struct Array *arr)
{
    int size = 0;
    int length = 0;
    printf("Enter size of the array:");
    scanf("%d", &size);

    arr = (struct Array *)malloc(sizeof(struct Array));
    arr->length = 0;
    arr->size = size;

    printf("Enter length of the array:");
    scanf("%d", &length);
    printf("Enter %d elements:\n", length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr->A[i]);
    }
    arr->length = length;
    return arr;
}

void append(struct Array *arr, int ele)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = ele;
    }
    else
    {
        printf("No space left in array.\n");
    }
}

void insert(struct Array *arr, int index, int ele)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = ele;
        arr->length++;
    }
    else
    {
        printf("Invalid Index.\n");
    }
}

void delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

int search(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void display(struct Array a)
{
    printf("\nArray elements:\n");
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.A[i]);
    }
}