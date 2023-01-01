#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n; // n Nodes
    int m; // m Edges
    cin>>n>>m;

    vector<int> adjList[n+1]; 
    // Adjacency List

    for(int i=0; i<n; i++)
    {
        int u;
        int v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        // In case of Weighted Graphs,
        // Construct the Adjacency List as
        // vector<pair<int,int>> adjList[n+1];
    }
}
