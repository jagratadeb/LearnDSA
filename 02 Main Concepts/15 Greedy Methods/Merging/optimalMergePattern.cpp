#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int optimalMerge(vector<int> &files)
{
    // Min-heap using priority_queue with greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());

    int totalCost = 0;

    while (minHeap.size() > 1)
    {
        // Extract two smallest
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int cost = first + second;
        totalCost += cost;

        // Push merged file back
        minHeap.push(cost);
    }

    return totalCost;
}

int main()
{
    vector<int> files = {20, 30, 10, 5, 30}; // file sizes
    cout << "Minimum cost of merging: " << optimalMerge(files) << endl;
    return 0;
}
