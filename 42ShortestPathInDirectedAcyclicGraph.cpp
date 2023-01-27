/*
Practice Link
https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
*/

class Solution 
{
private :
    void topoDFS(int node, vector<pair<int,int>> adj[], int visited[], stack<int>&st)
    {
        visited[node] = 1;
        
        for(auto it : adj[node])
        {
            int adjacent = it.first;
            // Because it is stored as {adjacent,distance} pair
            if(visited[adjacent]==0)
            {
                topoDFS(adjacent,adj,visited,st);
            }
        }
        
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        // Graph
        vector<pair<int,int>> adj[N];
        
        // Constructing the Graph
        for(int i=0; i<M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        // Perform Topological Sort
        stack<int>st;
        
        int visited[N] = {0};
        
        for(int i=0; i<N; i++)
        {
            if(visited[i]==0)
            {
                topoDFS(i,adj,visited,st);
            }
        }
        
        vector<int>distance(N,1e9);
        distance[0] = 0;
        // Distance of Source Node is 0
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                int adjacent = it.first;
                int wt = it.second;
              // If Distance via this node is Lesser Than existing Distance in the Distance Array, Update 
                if(distance[node]+wt < distance[adjacent])
                {
                    distance[adjacent] = distance[node] + wt;
                }
            }
        }
        
       // If distance arrau contains Infinites, or 1e9, it indicates these Nodes are Unreachable
       // Hence make them -1
        for(int i=0; i<N; i++)
        {
            if(distance[i]==1e9)
            {
                distance[i] = -1;
            }
        }
        return distance;
        
     
    }
};
