
#include <stdio.h>
#define INF 9999
int parent[10];
void prim(int graph[10][10], int V)
{int visited[10] = {0};
    int edges = 0;
    int totalCost = 0;
    visited[0] = 1;   // Start from vertex 0
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < V - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < V; j++)
                {
                    if (visited[j] == 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d -- %d = %d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("Minimum cost = %d\n", totalCost);
}

int main()
{
    int V;
    int graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    prim(graph, V);

    return 0;}
