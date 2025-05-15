#include <stdio.h>

void display(int arr[], int size)
{
    printf("\nArray:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findDuplicate(int arr[], int size)
{
    int lastDuplicate = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == arr[i+1] && lastDuplicate != arr[i]){
            lastDuplicate = arr[i];
            printf("Duplicate Element: %d\n", arr[i]);
        }
    }
}

int main()
{
    int arr[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int size = sizeof(arr) / sizeof(int);
    display(arr, size);
    findDuplicate(arr, size);
    return 0;
}