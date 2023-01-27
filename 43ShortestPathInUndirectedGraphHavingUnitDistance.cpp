/*
Practice Link :
https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
       // Graph
       vector<int> adj[N];
       
       for(auto it : edges)
       {
           int u = it[0];
           int v = it[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
            // Case of an Undirected Graph  
       }
       
       queue<int>q;
       // Queue that stores {node,distance}
       vector<int>distance(N,1e9);
       
       q.push(src);
       // Push source Node into the Queue
       distance[src] = 0;
       // Initialize Source Node's Distance to 0
       
       while(!q.empty())
       {
           int node = q.front();
           q.pop();
           for(auto it : adj[node])
           {
               if(distance[node]+1 < distance[it])
               {
                   distance[it] = distance[node] +1;
                   q.push(it);
               }
           }
       }
       
       // Set the Unreachable Nodes as -1
       for(int i=0; i<N; i++)
       {
           if(distance[i]==1e9) distance[i] = -1;
       }
       return distance;
    }
};
