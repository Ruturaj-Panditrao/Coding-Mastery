/*
Practice Link
https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
*/

class Solution {
  private :
  
  bool detect(int node, int visited[], vector<int>adj[])
  {
      visited[node] = 1;
      
      // Custom Queue containing node & it's parent
      
      queue<pair<int,int>>q;
      
      q.push({node,-1});
      
      while(!q.empty())
      {
          int curnode = q.front().first;
          int parent = q.front().second;
          
          q.pop();
          
          for(auto it : adj[curnode])
          {
              if(visited[it]==0)
              {
                  visited[it]=1;
                  q.push({it,curnode});
              }
              else if(visited[it]==1)
              {
                  if(it!=parent)
                  {
                      // Mere adjacency List mein koi Visited hain,
                      // But wo mera Parent Nahi Hain !
                      // How is it Possible?
                      // It means somebody else has touched t
                      // There is a Cycle
                      return true;
                  }
              }
          }
      }
      
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // 0 based indexing
        int visited[V] = {0};
        
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
            {
                if(detect(i,visited,adj)==true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
