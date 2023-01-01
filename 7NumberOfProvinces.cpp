/*
Practice Link
https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces
*/

class Solution {
  public:
    void bfs(int node, vector<vector<int>>&adj, vector<bool>&visited)
    {
            visited[node] = true;
            queue<int>q;
            q.push(node);
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                for(int it=0;it<adj[temp].size();it++)
                {
                    if(visited[it]==false && adj[temp][it]==1)
                    {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
    }
    
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<bool>visited(V+1,false);
        // The indexing as 0,1,2 or 1,2,3 does not matter
      // Let the Graph start from any point or node, we just need to know how many times we need to apply BFS over components
        int counter = 0;
        
        for(int i=0; i<V; i++)
        {
            if(visited[i]==false)
            {
                counter++;
                bfs(i,adj,visited);
            }
        }
        return counter;
    }
};
