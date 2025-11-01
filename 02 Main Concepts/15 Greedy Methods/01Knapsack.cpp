#include <iostream>
using namespace std;

void sortItems(double obj[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double r1 = obj[i][0] / obj[i][1];
            double r2 = obj[j][0] / obj[j][1];
            if (r1 < r2)
            {
                swap(obj[i][0], obj[j][0]);
                swap(obj[i][1], obj[j][1]);
            }
        }
    }
}

double knapsack(double obj[][2], int n, int capacity)
{
    sortItems(obj, n);
    double profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (obj[i][1] <= capacity)
        {
            profit += obj[i][0];
            capacity = capacity - obj[i][1];
        }
        else
        {
            profit += obj[i][0] * capacity / obj[i][1];
            break;
        }
    }
    return profit;
}

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    double obj[n][2];
    cout << "Enter profit and weight for each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> obj[i][0] >> obj[i][1];
    }
    double maxProfit = knapsack(obj, n, capacity);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
