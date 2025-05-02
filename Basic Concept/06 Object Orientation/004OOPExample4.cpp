#include <iostream>
using namespace std;

class Arithmetic
{
private:
    int a;
    int b;
public:
    Arithmetic(int a, int b);
    int add();
    int sub();
    ~Arithmetic();
};

Arithmetic::Arithmetic(int a, int b)
{
    this->a = a;
    this->b = b;
}
int Arithmetic::add()
{
    int c = a + b;
    return c;
}
int Arithmetic::sub()
{
    int c = a - b;
    return c;
}
Arithmetic::~Arithmetic()
{
    cout << "Destructor called" << endl;
};

int main()
{
    Arithmetic A = {100, 50};
    cout << "\nAdd = " << A.add() << endl;
    cout << "Sub = " << A.sub() << endl << endl;
    return 0;
}