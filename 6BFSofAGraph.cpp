/*
Practice Link
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Graph starts from 0
        vector<bool>visited(V,0);
        queue<int>q;
        
        int start = 0;
        visited[start] = 1;
        q.push(start);
        
        vector<int>bfs;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
};
