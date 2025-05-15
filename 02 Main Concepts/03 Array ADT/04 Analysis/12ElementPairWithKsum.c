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

void findPair(int arr[], int size, int K)
{
    int x;
    for (int i = 0; i < size; i++)
    {
        x = K - arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] == x)
            {
                printf("%d + %d = %d\n", arr[i], x, K);
            }
        }
    }
}

// Simpler and easier method
// void findPair(int arr[], int size, int K)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i + 1; j < size; j++)
//         {
//             if (arr[i] + arr[j] == K)
//             {
//                 printf("%d + %d = %d\n", arr[i], arr[j], K);
//             }
//         }
//     }
// }

int main()
{
    int arr[11] = {0, 2, 5, 7, 4, 9, 6, 8, 10, 1, 3};
    int size = sizeof(arr) / sizeof(int);
    int K = 10;
    display(arr, size);
    findPair(arr, size, K);
    return 0;
}