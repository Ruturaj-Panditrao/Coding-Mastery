/*
Practice Link
https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
*/

class Solution {
    bool dfsCheck(int node, vector<int> adj[], int visited[], int pathvisited[], int check[])
    { 
        // Mark the Current Node as Visited
        visited[node] = 1;
        
        // Mark its Path
        pathvisited[node] = 1;
        
        // Explore the Adjacency List of that Node
        for(auto it : adj[node])
        {
            // If adj node has not been visited
            if(visited[it]==0)
            {
                if(dfsCheck(it,adj,visited,pathvisited,check)==true)
                {
                    // If it any point this unvisited Node is a part of the cycle
                    // Mark it as checked, it cannot be a safe node
                    check[node] =0;
                    return true;
                }
            }
            // If adj node has already been visited
            if(visited[it]==1)
            {
                // If nodes have been visited on the same path,
                // They are apart of the cycle
                if(pathvisited[it]==visited[it])
                {
                    check[node] = 0;
                    return true;
                }
            }
        }
        // If after performing all of these traversals,
        // We reach the end,
        // It is a safe node
        // Because for cycle node, it would have broken out of the function
        // In earlier function calls
        check[node] = 1;
        pathvisited[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
      int visited[V] = {0};
      int pathvisited[V] = {0};
      int check[V] = {0};
      
      // To make sure all the Components are Being Covered
      for(int i=0; i<V; i++)
      {
          if(visited[i]==0)
          {
              dfsCheck(i,adj,visited,pathvisited,check);
          }
      }
      
      // Answer Vector
      vector<int>safeNodes;
      for(int i=0; i<V; i++)
      {
          if(check[i]==1)
          {
              safeNodes.push_back(i);
          }
      }
      
      return safeNodes;
    }
};
