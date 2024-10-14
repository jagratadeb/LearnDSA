#include <stdio.h>
#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle *r)
{
    return r->length * r->breadth;
}

int perimeter(Rectangle *r)
{
    int p;
    p = 2 * (r->length + r->breadth);
    return p;
}

int main()
{
    int length = 0, breadth = 0, A = 0, P = 0;
    struct Rectangle r;

    cout << "Enter the length and breadth:\n";
    cin >> r.length >> r.breadth;

    A = area(&r);
    P = perimeter(&r);

    cout << "Area:" << A << endl
    << "Perimeter:" << P << endl;

    return 0;
}