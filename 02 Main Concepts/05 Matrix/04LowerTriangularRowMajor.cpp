#include <iostream>
using namespace std;

class LowerTriangle
{
private:
    int *A;
    int dimension;

public:
    LowerTriangle(int n)
    {
        this->dimension = n;
        A = new int[((n * (n + 1)) / 2) * sizeof(int)];
    }
    void set(int i, int j, int ele);
    int get(int i, int j);
    void display();
    ~LowerTriangle()
    {
        delete[] A;
    }
};

void LowerTriangle::set(int i, int j, int ele)
{
    if (i >= j)
    {
        A[((i * (i - 1)) / 2) + (j - 1)] = ele;
    }
}

int LowerTriangle::get(int i, int j)
{
    if (i >= j)
        return A[((i * (i - 1)) / 2) + (j - 1)];
    else
        return 0;
}

void LowerTriangle::display()
{
    for (int i = 1; i <= dimension; i++)
    {
        for (int j = 1; j <= dimension; j++)
        {
            if (i >= j)
            {
                cout << A[((i * (i - 1)) / 2) + (j - 1)] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    int n = 0;
    cout << "Enter the dimension: ";
    cin >> n;
    LowerTriangle M(n);

    cout << "Enter all elements: ";
    int ele;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ele;
            M.set(i, j, ele);
        }
    }
    cout << "\n";
    M.display();

    int row, col;
    cout << "\nEnter row & col: ";
    cin >> row;
    cin >> col;
    cout << "Element at [" << row << "," << col << "] = " << M.get(row, col);
    return 0;
}