/*
Practice Link :
https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
*/

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
       // To store the Reverse Grapj
       vector<int>revAdj[V];
       
       int indegree[V] = {0};
       // Indegree Array to store Indegrees
       
       for(int i=0; i<V; i++)
       {
           for(auto it : adj[i])
           {
               revAdj[it].push_back(i);
               indegree[i]++;
           }
       }
       
       // Queue
       queue<int>q;
       
       // Push All Nodes with Indegree 0, into the Queue
       for(int i=0; i<V; i++)
       {
          if(indegree[i]==0) q.push(i);
       }
       
       vector<int>safeNodes;
       // To store Safe Nodes
       
       while(!q.empty())
       {
           int node = q.front();
           // If a node was Inserted into the Queue,
           // It means that it had 0 indegree in the first place
           // Hence it is definitely a Safe Node
           safeNodes.push_back(node);
           q.pop();
           
           for(auto it : revAdj[node])
           {
               indegree[it]--;
               if(indegree[it]==0)
               {
                   q.push(it);
               }
           }
       }
       
       // Sort the Safe Nodes Array
       sort(safeNodes.begin(),safeNodes.end());
       return safeNodes;
    }
    
};
