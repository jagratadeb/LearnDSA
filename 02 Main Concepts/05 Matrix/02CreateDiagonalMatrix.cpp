#include <stdio.h>
#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int dimension;

public:
    Diagonal(int n)
    {
        this->dimension = n;
        A = new int[dimension]; 
    }

    void set(int i, int j, int ele);
    int get(int i, int j);
    void display();
    ~Diagonal()
    {
        delete[] A; 
    }
};

void Diagonal::set(int i, int j, int ele)
{
    if (i == j)
    {
        A[i] = ele; // Corrected indexing
    }
}

int Diagonal::get(int i, int j)
{
    if (i == j)
        return A[i]; // Corrected indexing
    return 0;
}

void Diagonal::display()
{
    int i, j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if (i == j)
                printf("%d ", A[i]); // Corrected indexing
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    cout << "Enter the dimension of the diagonal matrix: ";
    cin >> n;

    Diagonal d(n);
    int ele;
    // Input diagonal elements
    cout << "Enter the diagonal elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Element [" << i << "," << i << "]: ";
        cin >> ele;
        d.set(i, i, ele);
    }

    cout << "\nThe diagonal matrix is:\n";
    d.display();

    // Example: get a value
    int row, col;
    cout << "\nEnter row and column to get value: ";
    cin >> row >> col;
    cout << "Value at [" << row << "," << col << "]: " << d.get(row, col) << endl;

    return 0;
}
