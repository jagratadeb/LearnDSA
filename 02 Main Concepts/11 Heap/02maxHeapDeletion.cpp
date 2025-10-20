#include <iostream>
using namespace std;

// Function prototypes
void display(int arr[], int n);
int insert(int heap[], int size);
int deleteRoot(int heap[], int size);

int main()
{
    int heap[100] = {0};
    int size = 0;

    size = insert(heap, size);
    size = insert(heap, size);
    size = insert(heap, size);

    display(heap, size);
    cout << endl;

    size = deleteRoot(heap, size);
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

int deleteRoot(int heap[], int size)
{
    if (size == 0)
    {
        cout << "Heap is empty!" << endl;
        return size;
    }

    // Replace root with the last element
    int root = heap[1];
    heap[1] = heap[size];
    size--;

    // Heapify downward
    int i = 1;
    while (i * 2 <= size)
    {
        int leftChild = i * 2;
        int rightChild = i * 2 + 1;
        int largerChild = leftChild;

        if (rightChild <= size && heap[rightChild] > heap[leftChild])
        {
            largerChild = rightChild;
        }

        if (heap[i] < heap[largerChild])
        {
            swap(heap[i], heap[largerChild]);
            i = largerChild;
        }
        else
        {
            break;
        }
    }

    cout << "Deleted root: " << root << endl;
    return size;
}
