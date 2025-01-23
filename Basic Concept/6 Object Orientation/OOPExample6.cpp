#include <iostream>
using namespace std;

template <class DT>
class Arithmatic
{
private:
    DT a;
    DT b;

public:
    Arithmatic(DT a, DT b);
    DT add();
    DT sub();

    ~Arithmatic() { cout << "Destructor is being called\n"; }
};

template <class DT>
Arithmatic<DT>::Arithmatic(DT a, DT b)
{
    this->a = a;
    this->b = b;
}

template <class DT>
DT Arithmatic<DT>::add()
{
    DT c;
    c = a + b;
    return c;
}
template <class DT>
DT Arithmatic<DT>::sub()
{
    DT c;
    c = a - b;
    return c;
}

int main()
{
    Arithmatic<int> A1(10, 5);
    cout << "Add = " << A1.add() << endl;
    cout << "Sub = " << A1.sub() << endl;

    Arithmatic<float> A2(10.012, 5);
    cout << "Add = " << A2.add() << endl;

    cout << "Sub = " << A2.sub() << endl;

    Arithmatic<char> A3('B', 'A');
    cout << "Add = " << (int)A3.add() << endl;
    // B(66) + A(65) = 131 (greater than 127)
    // 131 - 256 (since it is an 8-bit signed integer)
    // so the output is negative -> -125)
    cout << "Sub = " << (int)A3.sub() << endl;
    return 0;
}