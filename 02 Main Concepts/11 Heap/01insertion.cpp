#include <iostream>
using namespace std;

// Function prototype
void display(int arr[], int n);
int insert(int heap[], int size);

int main()
{
    int heap[100] = {0};
    int size = 0;

    size = insert(heap, size);
    size = insert(heap, size);
    size = insert(heap, size);

    display(heap, size);

    return 0;
}

void display(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

int insert(int heap[], int size)
{
    int element;
    cin >> element;

    size++;
    int i = size;

    while (i > 1 && element > heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = element;

    return size;
}