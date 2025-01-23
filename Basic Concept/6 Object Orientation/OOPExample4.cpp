#include <iostream>
using namespace std;

class Arithmatic
{
private:
    int a;
    int b;

public:
    Arithmatic(int a, int b);
    int add();
    int sub();

    ~Arithmatic();
};

Arithmatic::Arithmatic(int a, int b)
{
    this->a = a;
    this->b = b;
}
int Arithmatic::add()
{
    int c = a + b;
    return c;
}
int Arithmatic::sub()
{
    int c = a - b;
    return c;
}
Arithmatic::~Arithmatic()
{
    cout << "Destructor called" << endl;
};

int main()
{
    Arithmatic A = {100, 50};
    cout << "\nAdd = " << A.add() << endl;
    cout << "Sub = " << A.sub() << endl << endl;

    return 0;
}