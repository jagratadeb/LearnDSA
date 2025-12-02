#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITE INT_MAX

struct Edge
{
    int u, v, w;
};

int find(int parent[], int x)
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(int parent[], int rank[], int x, int y)
{
    int rx = find(parent, x);
    int ry = find(parent, y);
    if (rx == ry)
        return;

    if (rank[rx] < rank[ry])
    {
        parent[rx] = ry;
    }
    else if (rank[rx] > rank[ry])
    {
        parent[ry] = rx;
    }
    else
    {
        parent[ry] = rx;
        rank[rx]++;
    }
}

int kruskal(struct Edge edges[], int edgeCount, int n)
{
    int *selected = (int *)calloc(edgeCount, sizeof(int));
    int *parent = (int *)malloc((n + 1) * sizeof(int)); // +1 for 1-based vertices
    int *rank = (int *)calloc((n + 1), sizeof(int));

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int minCost = 0;
    int mstEdges = 0;

    while (mstEdges < n - 1)
    {
        int min = INFINITE;
        int index = -1;

        for (int i = 0; i < edgeCount; i++)
        {
            if (!selected[i] && edges[i].w < min)
            {
                min = edges[i].w;
                index = i;
            }
        }

        if (index == -1)
            break;

        int u = edges[index].u;
        int v = edges[index].v;

        if (find(parent, u) != find(parent, v))
        {
            unite(parent, rank, u, v);
            printf("Edge %d: (%d, %d) cost: %d\n", mstEdges++, u, v, min);
            minCost += min;
            selected[index] = 1;
        }
        else
        {
            selected[index] = 1;
        }
    }

    free(selected);
    free(parent);
    free(rank);

    return minCost;
}

int main()
{
    int n = 7; // vertices are 1..7
    int edgeCount = 9;

    struct Edge edges[] = {
        {1, 2, 28},
        {1, 6, 10},
        {2, 3, 16},
        {2, 7, 14},
        {3, 4, 12},
        {4, 5, 22},
        {4, 7, 18},
        {5, 6, 25},
        {5, 7, 24}};

    printf("Minimum Cost Spanning Tree:\n");
    int cost = kruskal(edges, edgeCount, n);
    printf("Total cost of MST = %d\n", cost);

    return 0;
}
