#include <stdio.h>

#define MAX 100

int A[MAX][MAX];  // adjacency matrix
int visited[MAX]; // visited array
int n;            // number of vertices

void dfs(int u)
{
    if (visited[u] == 0)
    {
        printf("%d ", u);
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                dfs(v);
            }
        }
    }
}

int main()
{
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            A[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        A[u][v] = 1;
        A[v][u] = 1; // undirected graph
    }

    // initialize visited array
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    printf("DFS Traversal starting from node 1:\n");
    dfs(1);

    return 0;
}
