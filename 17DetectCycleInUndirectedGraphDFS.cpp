/*
Practice Link 
https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
*/

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(int node, int parent, vector<int> adj[], int visited[])
    {
        visited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
                // Node has not been visited
                if(detect(it,node,adj,visited)==true)
                {
                    return true;
                }
            }
            else if(it!=parent)
            {
                // It has been visited,
                // And it is not the parent
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
            {
                // If a Node is Unvisited
                if(detect(i,-1,adj,visited)==true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
