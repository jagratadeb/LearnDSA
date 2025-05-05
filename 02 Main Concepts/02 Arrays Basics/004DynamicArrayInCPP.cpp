#include <iostream>
using namespace std;

int main()
{
    // Declare a pointer for the dynamic array
    int* p;
    int size;

    // Ask the user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Allocate memory for the array dynamically
    p = new int[size];

    // Input elements into the array
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> p[i];
    }

    // Print the elements of the array
    cout << "Elements of the dynamic array are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    // Deallocate the memory
    delete []p;

    return 0;
}