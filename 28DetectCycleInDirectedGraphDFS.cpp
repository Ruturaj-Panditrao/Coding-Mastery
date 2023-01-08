/*
Practice Link
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
*/

class Solution 
{
private :
    bool dfsDetect(int node,vector<int>adj[],int visited[],int pathvisited[])
    {
        visited[node] = 1;
        pathvisited[node] =1; 
        // On the Same Path, 
        // As the Recursion Goes Deeper
        
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
                if(dfsDetect(it,adj,visited,pathvisited)==true)
                {
                    return true;
                }
            }
            if(pathvisited[it]==1)
            {
                return true;
            }
        }
        
        pathvisited[node] = 0;
        // Mark it 0, while coming back
        // New Path is being Explored
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // Visited Array
        int visited[V] = {0};
        // Path Visited Array
        int pathvisited[V] = {0};
        
        // To make sure that all the Components are Covered
        
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
            {
                if(dfsDetect(i,adj,visited,pathvisited)==true)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
