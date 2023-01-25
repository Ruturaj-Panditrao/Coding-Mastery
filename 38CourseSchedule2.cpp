/*
Practice Link
https://leetcode.com/problems/course-schedule-ii/description/
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
     // Number of Courses = Number of Vertices for Graph
     int V = numCourses;

     // Construct the Graph
     vector<int> adj[V];

     // Fill the Graph with Appropriate Directed Edges
     for(auto it : prerequisites)
     {
         adj[it[1]].push_back(it[0]);
     }

     // Indegree Array
     vector<int> indegree(V,0);

     // Fill the Indegree Array
     for(int i=0; i<V; i++)
     {
         for(auto it : adj[i])
         {
             indegree[it]++;
         }
     }

     // Queue
     queue<int>q;

     // Fill Queue with Nodes Indegree 0
     for(int i=0; i<V; i++)
     {
        if(indegree[i]==0)
        {
            q.push(i);
        }
     }
    
    vector<int> topoSort;
    // Answer Vector 

    // Kahn's Algorithm to Find Topological Ordering
    while(!q.empty())
    {
        int node = q.front();
        // Add node to Topological Ordering
        topoSort.push_back(node);
        q.pop();

        for(auto it : adj[node])
        {
            // Reduce the Indegree of Related Nodes
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(topoSort.size()==V) return topoSort; // Valid Ordering is Possible
    else return {}; // No ordering is Possible
    }
};
