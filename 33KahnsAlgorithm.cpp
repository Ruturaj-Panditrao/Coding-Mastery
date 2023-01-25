/*
Practice Link :
https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Indegree Array
	    int indegree[V] = {0};
	    
	    // Queue
	    queue<int>q;
	    
	    // Find indegree for each node 
	    for(int i=0; i<V; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    for(int i=0; i<V; i++)
	    {
	        if(indegree[i]==0) q.push(i);
	    }
	    // Push all the Nodes with indegree 0 into the Queue
	    
	    vector<int>ans;
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        ans.push_back(node);
	        // Add node to the Topological Sort
	        q.pop();
	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            // Remove Node and
	            // Reduce the Corresponding Indegrees
	            if(indegree[it]==0)
	            {
	                // If in the process indegree of any node becomes 0.
	                // Push it onto the Queue
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};
