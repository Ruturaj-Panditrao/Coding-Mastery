/*
Practice Link :
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // Indegree Array
        int indegree[V] = {0};
        // Calculate Indegree for Each Node
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        // Queue
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        // Pushed all Nodes with Indegree 0, into the Queue
        
        int topoCount = 0;
        while(!q.empty())
        {
            int node = q.front();
            // Increment the topoCount
            topoCount++;
            q.pop();
            for(auto it : adj[node])
            {
                indegree[it]--;
                // Removed the Node
                // Reduce Indegrees of Connected Nodes
                if(indegree[it]==0) q.push(it);
            }
        }
        
        // Each Node goes into the Queue exactly Once
        // If count of TopoSort is not equal to that of number of Vertices,
        // It means Topological Sort was not possible,
        // And the Graph contains a Cycle
        if(topoCount==V) return false;
        else return true;
    }
};
