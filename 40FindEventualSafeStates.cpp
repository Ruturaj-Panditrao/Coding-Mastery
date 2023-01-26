/*
Practice Link
https://leetcode.com/problems/find-eventual-safe-states/description/
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        // The Number of Vertices
        int V = graph.size();
        
        // To store the Reverse Graph  
        vector<int> revAdj[V];

        // Indegree Array
        vector<int>indegree(V,0);

        for(int i=0; i<V; i++)
        {
            for(auto it : graph[i])
            {
                revAdj[it].push_back(i);
                indegree[i]++;
                // Filling up the Indegree Array
            }
        }

        // Queue
        queue<int>q;

        // Push all Nodes with Indegree 0 into the Queue
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        // Vector to Store Safe Nodes
        vector<int>safeNodes;

        while(!q.empty())
        {
            int node = q.front();
            // Since Node Entered the Queue
            // It had indegree 0
            safeNodes.push_back(node);
            q.pop();

            for(auto it : revAdj[node])
            {
                // Reduce indegree of Related Nodes
                // And remove the Nodes
                indegree[it]--;
                // If indegree of an Adjacent Node becomes 0,
                // Push it into the Queue
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
