#include <iostream>
using namespace std;

int main()
{
    // Declare and initialize a static array
    static int arr[5] = {1, 2, 3, 4, 5};

    // Print the elements of the static array
    cout << "Elements of the static array are:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}