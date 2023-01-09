/*
Practice Link
https://leetcode.com/problems/find-eventual-safe-states/description/
*/

class Solution {
    bool dfsCheck(int node, vector<vector<int>>&graph, vector<int>&visited, 
    vector<int>&pathvisited, vector<int>&check)
    {
        // When you encounter a Node,
        // Mark it as Visited

        visited[node] = 1;
        pathvisited[node] = 1;
        // Mark its path

        // Explore Neighbours of the Node.
        // i.e Explore its Adjacency List

        for(auto it : graph[node])
        {
            // If an adjacent node is unvisited
            // Make further explorations
            // Make DFS calls for this node

            if(visited[it]==0)
            {
            if(dfsCheck(it,graph,visited,pathvisited,check)==true)
            {
                // If at any point cycle is detected, 
                // It will never be a safe node
                check[node] = 0;
                return true;
            }
            }
            // If a node is already visited
            // And it is in the same path as current node
            // This indicates a cycle
            // And will never be a safe node

            if(visited[it]==1)
            {
                if(pathvisited[it]==pathvisited[node])
                {
                    check[node] = 0;
                    return true;
                }
            }
        }

        // If the code runs until here,
        // And hasn't exited yet,
        // It means that this node is not a part of any cycle

        check[node] = 1;
        pathvisited[node] = 0;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        // Number of Vertices
        int V = graph.size();

        // Visited Array
        vector<int>visited(V,0);

        // Path visited Array
        // To check whether a cycle has been encountered
        vector<int>pathvisited(V,0);

        // Check Array 
        // To keep a track of the safe nodes
        vector<int>check(V,0);

        // To make sure all the Components of the Graph are Visited
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
            {
                dfsCheck(i,graph,visited,pathvisited,check);
            }
        }

        vector<int>answer;
        // Check if a node is safe node, add it to our answer vector 
        for(int i=0; i<V; i++)
        {
            if(check[i]==1)
            {
                answer.push_back(i);
            }
        }
        return answer;
        // Return our answer vector
    }
};
