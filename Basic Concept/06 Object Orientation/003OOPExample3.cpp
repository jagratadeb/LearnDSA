/*
Concepts learned:
- Class and Object: 
Definition and usage of classes and objects to encapsulate data and functions.

- Constructor: 
Special member function used to initialize objects. Two constructors are defined: a default constructor and a parameterized constructor.

- Destructor: 
Special member function used to clean up resources when an object is destroyed.

- Member Functions: 
Functions defined within a class to operate on the data members of the class, such as area(), perimeter(), getLength(), getBreadth(), setLength(), and setBreadth().

- Encapsulation: 
Bundling of data (length and breadth) and functions that operate on the data within a single unit (class).

- Access Specifiers: 
Use of private and public to control access to class members.

- Function Overloading: 
Multiple constructors with different parameters to initialize objects in different ways.
*/

#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {
        length = 10;
        breadth = 5;
    }
    Rectangle(int l, int b)
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
        int p = 2 * (length + breadth);
        return p;
    }

    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
    }

    void setLength(int l)
    {
        length = l;
    };
    void setBreadth(int b)
    {
        breadth = b;
    };
    ~Rectangle()
    {
        cout << "\nDestructor function has been called.\n\n";
    }
};

int main()
{
    Rectangle r = {15, 5};
    cout << "Length = " << r.getLength() << endl;
    cout << "Breadth = " << r.getBreadth() << endl;
    cout << "Area = " << r.area() << endl;
    cout << "Perimeter = " << r.perimeter() << endl;

    r.setLength(20);
    cout << "Length = " << r.getLength() << endl;
    cout << "Breadth = " << r.getBreadth() << endl;
    cout << "Area = " << r.area() << endl;
    cout << "Perimeter = " << r.perimeter() << endl;

    return 0;
}