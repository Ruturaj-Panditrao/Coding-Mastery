/*
Practice Link :
https://leetcode.com/problems/course-schedule/description/
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // For our case,
        // Number of Courses = Number of Vertices for the Graph
        int V = numCourses;    

        // Construct Graph for the Given List
        vector<int> adj[V];

        // {a,b} Edge should be of the form : b->a
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        // Now we try to perform Topological Sort using Kahn's Algorithm

        // Indegree Array
        vector<int>indegree(V,0);

        // Fill up the Indegree Array
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // Queue
        queue<int>q;

        // All Nodes with Indegree 0 are Pushed into the Queue
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        vector<int>topoSort;
        // Contains Topo Sort if Possible
        while(!q.empty())
        {
            int node = q.front();
            // Add Node into the Topological Sort
            topoSort.push_back(node);
            q.pop();

            // Reduce Indegree of all Related Nodes
            for(auto it : adj[node])
            {
                indegree[it]--;
                // If indegree of any of the Nodes becomes 0, push it into the Queue
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        // If a Topological Ordering is Possible,
        // It means all the Tasks can be completed in some way and some order,
        // Return true
        if(topoSort.size()==V) return true;
        else return false;
    }
};
