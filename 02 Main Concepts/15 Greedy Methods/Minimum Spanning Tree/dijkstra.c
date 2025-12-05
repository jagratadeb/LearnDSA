#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 5 // number of nodes

int dijkstra(int cost[N][N], int n, int s, int d[])
{
    bool selected[N];

    // Initialize distances
    for (int i = 0; i < n; i++)
    {
        d[i] = cost[s][i];
        selected[i] = false;
    }
    d[s] = 0;
    selected[s] = true;

    // Repeat n-1 times
    for (int k = 1; k < n; k++)
    {
        int min = INT_MAX, u = -1;

        // Find unselected node with minimum distance
        for (int i = 0; i < n; i++)
        {
            if (!selected[i] && d[i] < min)
            {
                min = d[i];
                u = i;
            }
        }

        selected[u] = true;

        // Relax edges
        for (int v = 0; v < n; v++)
        {
            if (!selected[v] && cost[u][v] != INT_MAX && d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
            }
        }
    }
    return 0;
}

int main()
{
    int cost[N][N] = {
        {0, 10, 3, INT_MAX, INT_MAX},
        {10, 0, 1, 2, INT_MAX},
        {3, 1, 0, 8, 2},
        {INT_MAX, 2, 8, 0, 7},
        {INT_MAX, INT_MAX, 2, 7, 0}};

    int d[N];
    dijkstra(cost, N, 0, d);

    printf("Shortest distances from source 0:\n");
    for (int i = 0; i < N; i++)
    {
        printf("To %d: %d\n", i, d[i]);
    }
    return 0;
}
