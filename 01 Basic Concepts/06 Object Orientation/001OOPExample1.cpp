#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle
{
public: // Now the class has become public
    int length;
    int breadth;

    void initialise(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        int p;
        p = 2 * (length + breadth);
        return p;
    }
};

int main()
{
    struct Rectangle r;
    r.initialise(10, 5);
    int A = r.area();
    cout << "\nArea of rectangle is " << A << "\n";
    int P = r.perimeter();
    cout << "Perimeter of rectangle is " << P << "\n\n";
    return 0;
}

// In CPP
// Structure and Class are same, but the only difference is that:
// STRUCTURE is PUBLIC
// CLASS is PRIVATE