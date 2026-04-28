#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// function declarations
vector<vector<int>> generate(int numRows); // generates Pascal's Triangle
void display(vector<vector<int>> vec);     // displays the triangle

int main()
{
    // variable and data structure declaration
    int numRows;
    vector<vector<int>> triangle;

    // get user input
    cout << "Number of rows: ";
    cin >> numRows;
    cout << endl;

    // function calls
    triangle = generate(numRows); // generate triangle
    display(triangle);            // display triangle

    return 0;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result; // stores all rows
    vector<int> row;            // stores current row

    // if 0 rows requested
    if (numRows == 0)
        return result;

    // first row always starts with 1
    row.push_back(1);
    result.push_back(row);

    // if only 1 row requested
    if (numRows == 1)
        return result;

    // build rows from 2 to numRows
    for (int i = 2; i <= numRows; i++)
    {
        vector<int> newRow = {1}; // every row starts with 1

        // compute middle elements using previous row
        for (int j = 1; j < i - 1; j++)
        {
            newRow.push_back(row[j - 1] + row[j]);
        }

        newRow.push_back(1);      // every row ends with 1
        result.push_back(newRow); // add new row to result
        row = newRow;             // update row for next iteration
    }

    return result;
}

void display(vector<vector<int>> vec)
{
    // print each row
    for (int i = 0; i < vec.size(); i++)
    {
        cout << setw((vec.size() - i) * 2);
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << "   "; // print elements with space
        }
        cout << endl; // move to next row
    }
}
