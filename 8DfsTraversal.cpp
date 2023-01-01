#include <vector>
#include <iostream>
using namespace std;

void dfs(int node, vector<bool>&vis, vector<vector<int>>&adj)
{
    vis[node] = true;
    cout<<node<<" ";
    for(auto it : adj[node])
    {
        if(vis[it]==false)
        {
            dfs(it,vis,adj);
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter Vertices : "; cin>>n;
    cout<<"Enter Edges : "; cin>>m;

    // Adjacency List

    vector<vector<int>>adj(n+1);

    // 1 Based
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        // For an Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout<<"Enter the Starting Node : "; cin>>start;

    vector<bool>vis(n+1,false);
    cout<<"DFS Traversal :\n";
    dfs(start,vis,adj);
}