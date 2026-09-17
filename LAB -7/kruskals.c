#include <stdio.h>
struct Edge
{  int src;
    int dest;
    int weight;
};
int parent[100];
void sortEdges(struct Edge edges[], int E)
{
    int i, j;
    struct Edge temp;

    for (i = 0; i < E - 1; i++)
    {
        for (j = 0; j < E - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSets(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void kruskal(struct Edge edges[], int V, int E)
{ int i;
    int edgeCount = 0;
    int totalWeight = 0;
    for (i = 0; i < V; i++)
        parent[i] = i;
    sortEdges(edges, E);
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        if (find(u) != find(v))
        {   printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSets(u, v);
            edgeCount++; }  }
    printf("Minimum cost = %d\n", totalWeight);
}
int main()
{ int V, E;
    int i;
    struct Edge edges[100];
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter source, destination and weight:\n");

    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }
    kruskal(edges, V, E);
    return 0;
}
