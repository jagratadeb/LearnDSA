#include <stdio.h>

#define MAX 100

int A[MAX][MAX];  // adjacency matrix
int visited[MAX]; // visited array
int q[MAX];       // queue
int front = -1, rear = -1;
int n; // number of vertices

// Queue operations
void enqueue(int x)
{
    if (rear == MAX - 1)
        return; // overflow check
    if (front == -1)
        front = 0;
    q[++rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1; // underflow check
    return q[front++];
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

// BFS 
void bfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        int u = dequeue();
        for (int v = 1; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                printf("%d ", v);
                visited[v] = 1;
                enqueue(v);
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

    printf("BFS Traversal starting from node 1:\n");
    bfs(1);

    return 0;
}
