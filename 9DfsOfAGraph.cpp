/*
Practice Link
https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
*/

// Make sure to Pass Vectors by Refference as in C++, vectors are passed by Value by Default
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<bool>& visited, vector<int> adj[], vector<int>&dfsAns)
    {
        visited[node] = true;
        dfsAns.push_back(node);
        for(auto it : adj[node])
        {
            if(visited[it]==false)
            {
                dfs(it,visited,adj,dfsAns);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>dfsAns;
        // 0 Based Graph
        vector<bool>visited (V,false);
        dfs(0,visited,adj,dfsAns);
        return dfsAns;
    }
};
