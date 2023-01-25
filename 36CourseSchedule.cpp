/*
Practice Link

https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

*/

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        // Total Tasks = Number of Vertice
        int V = n;
       // Construct Graph
       vector<int>adj[V];
       
       for(auto it : prerequisites)
       {
           adj[it[1]].push_back(it[0]);
       }
       
       // Indegree Array initialized to zeroes
       int indegree[V] = {0};
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
       // Fill the Queue with nodes having Indegree 0
       for(int i=0; i<V; i++)
       {
           if(indegree[i]==0) q.push(i);
       }
       // Will Contain the Topological Sort
       vector<int>topoSort;
       while(!q.empty())
       {
           int node = q.front();
           // Add it to the TopoSort
           topoSort.push_back(node);
           q.pop();
           
           for(auto it : adj[node])
           {
               // Reduce indegrees of all associated nodes
               indegree[it]--;
               if(indegree[it]==0)
               {
                   // If indegree of any node becomes 0,
                   // Push into the Queue
                   q.push(it);
               }
           }
       }
       
       if(topoSort.size()==V) return topoSort;
       else return {};
    }
};
