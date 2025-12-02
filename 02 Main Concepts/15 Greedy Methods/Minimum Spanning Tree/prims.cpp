#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITE INT_MAX

// Prim’s Algorithm
int prims(int graph[10][10], int n)
{
    int selected[10]; // track visited vertices
    for (int i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1; // start from vertex 0
    int edgeCount = 0;
    int minCost = 0;

    while (edgeCount < n - 1)
    {
        int u = -1, v = -1;
        int min = INFINITE;

        // Find minimum edge connecting visited to unvisited
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        if (u != -1 && v != -1)
        {
            printf("Edge %d: (%d, %d) cost: %d\n", edgeCount++, u, v, min);
            minCost += min;
            selected[v] = 1;
        }
    }

    return minCost;
}

// Main function
int main()
{
    int n = 7; // number of vertices
    // adjacency matrix representation of graph
    int graph[10][10] = {
        {0, 28, 0, 0, 0, 10, 0},
        {28, 0, 16, 0, 0, 0, 14},
        {0, 16, 0, 12, 0, 0, 0},
        {0, 0, 12, 0, 22, 0, 18},
        {0, 0, 0, 22, 0, 25, 24},
        {10, 0, 0, 0, 25, 0, 0},
        {0, 14, 0, 18, 24, 0, 0}};

    printf("Minimum Cost Spanning Tree using Prim's Algorithm:\n");
    int cost = prims(graph, n);
    printf("Total cost of MST = %d\n", cost);

    return 0;
}
