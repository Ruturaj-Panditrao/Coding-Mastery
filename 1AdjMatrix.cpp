#include <iostream>
using namespace std;

int main()
{
    int n; // n Nodes
    int m; // m Edges

    cin>>n>>m;
    
    // Adjacency Matrix
    int adj[n+1][n+1];

    for(int i=0; i<m; i++)
    {
        int u;
        int v;
        cin>>u>>v;
        adj[u][v] = 1;
        // else adj[u][v] = weight
        adj[v][u] = 1;
        // else adj[u][v] = weight
    }
}
