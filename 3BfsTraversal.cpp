#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
    int n; // Vertices
    int m; // Edges
    cout<<"Vertices : ";
    cin>>n;
    cout<<"Edges : ";
    cin>>m;

    vector<int> Graph[n+1];
    // An array of Vectors
    // int arr
    // Each element of arr is an integer,
    // Similarly,
    // vector<int> arr
    // Each element of arr is a vector

    vector<bool>visited(n+1,0);
    for(int i=0; i<m; i++)
    {
        int u;
        int v;
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        // Suppose there is an edge from 1 to 2
        // So go to first index, append to 2 to its corresponding vector of adjacent vertices
        // Also, go to second index, append 1 to its corresponding vector of adjacent vertices
    }

    queue<int>q;
    int start;
    cout<<"Starting Vertex : ";
    cin>>start;
    q.push(start);
    visited[start] = 1;

    // Put the starting vertex into the Queue;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        // Once a Node has been printed,
        // Go to each node in its adjacency list,
        // If it has not been visited, visit it and put into the queue
        
        for(auto i : Graph[node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }

    }
}