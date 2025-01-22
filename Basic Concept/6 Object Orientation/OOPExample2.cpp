#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    // constructors have the same name as class name
    Rectangle()
    // default constructor
    {
        length = 100;
        breadth = 2;
    }
    Rectangle(int l, int b);
    // parameterized constructor

    int area();      // facilitator (which performs some operation on the data members of an object)
    int perimeter(); // facilitaor

    int getLength() // accessor
    {
        return length;
    }
    int getBreadth() // accessor
    {
        return breadth;
    }
    int setLength(int l) // mutator
    {
        length = l;
        cout << "The new Length is now set to " << l << endl;
    }
    ~Rectangle(); // Destructor
};


// scope resolution operator
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
};

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

Rectangle::~Rectangle() {};

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