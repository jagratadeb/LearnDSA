#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }

    void createArray()
    {
        cout << "Enter size of the array: ";
        cin >> size;

        delete[] A; // Free previously allocated memory
        A = new int[size];
        length = 0;

        cout << "Enter length of the array: ";
        cin >> length;

        if (length > size)
        {
            cout << "Length cannot be greater than size. Setting length to size.\n";
            length = size;
        }

        cout << "Enter " << length << " elements:\n";
        for (int i = 0; i < length; i++)
        {
            cin >> A[i];
        }
    }

    void display()
    {
        cout << "\nArray elements:\n";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void append(int ele)
    {
        if (length < size)
        {
            A[length++] = ele;
        }
        else
        {
            cout << "No space left in array.\n";
        }
    }

    void insert(int index, int ele)
    {
        if (index >= 0 && index <= length)
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = ele;
            length++;
        }
        else
        {
            cout << "Invalid Index.\n";
        }
    }

    void Delete(int index)
    {
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            length--;
        }
        else
        {
            cout << "Invalid Index.\n";
        }
    }

    int search(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Array arr;
    arr.createArray();

    int choice = 0;
    do
    {
        cout << "\n\nMenu Driver\n";
        cout << "1. Display\n";
        cout << "2. Append\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        int ele = 0;
        int index = 0;
        switch (choice)
        {
        case 1:
            arr.display();
            break;
        case 2:
            cout << "Enter element to append: ";
            cin >> ele;
            arr.append(ele);
            break;
        case 3:
            cout << "Enter element and index to insert: ";
            cin >> ele >> index;
            arr.insert(index, ele);
            break;
        case 4:
            cout << "Enter index to delete: ";
            cin >> index;
            arr.Delete(index);
            break;
        case 5:
            cout << "Enter element to search: ";
            cin >> ele;
            index = arr.search(ele);
            if (index != -1)
            {
                cout << ele << " is available at index " << index << endl;
            }
            else
            {
                cout << ele << " is not found in the array." << endl;
            }
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Option.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}