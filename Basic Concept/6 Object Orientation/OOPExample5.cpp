/*
Explanation:

- Template:
A template is a feature in C++ that allows functions and classes to operate with generic types. This allows a function or class to work on different data types without being rewritten for each one.

- DT:
`DT` is a placeholder for a data type. When an object of the template class `Arithmetic` is created, `DT` is replaced with the actual data type specified (e.g., `int`, `float`, `double`).

- Template Declaration:
`template <class DT>` declares a template with a placeholder `DT`.

- Template Class:
`class Arithmetic` is defined as a template class that can handle different data types specified by `DT`.

- Template Member Functions: Member functions of the template class are defined using the template declaration `template <class DT>` and the scope resolution operator `Arithmetic<DT>::`.
*/

#include <iostream>
using namespace std;

template <class DT>
class Arithmetic
{
private:
    DT a; // First operand
    DT b; // Second operand

public:
    Arithmetic(DT a, DT b); // Constructor
    DT add();               // Function to add two operands
    DT sub();               // Function to subtract two operands

    ~Arithmetic(); // Destructor
};

template <class DT>
Arithmetic<DT>::Arithmetic(DT a, DT b)
{
    this->a = a; // Initialize first operand
    this->b = b; // Initialize second operand
}

template <class DT>
DT Arithmetic<DT>::add()
{
    DT c = a + b; // Add operands
    return c;
}

template <class DT>
DT Arithmetic<DT>::sub()
{
    DT c = a - b; // Subtract operands
    return c;
}

template <class DT>
Arithmetic<DT>::~Arithmetic()
{
    cout << "Destructor called" << endl; // Destructor message
}

int main()
{
    Arithmetic<int> A1(100, 50);            // Create object with int type
    cout << "\nAdd = " << A1.add() << endl; // Display result
    cout << "Sub = " << A1.sub() << endl
         << endl; // Display result

    Arithmetic<float> A2(100.1, 50.20); // Create object with float type
    cout << "\nAdd = " << A2.add() << endl;
    cout << "Sub = " << A2.sub() << endl
         << endl;

    Arithmetic<double> A3(100.561, 50.25); // Create object with double type
    cout << "\nAdd = " << A3.add() << endl;
    cout << "Sub = " << A3.sub() << endl
         << endl;

    return 0;
}
