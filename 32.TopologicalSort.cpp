/*
Practice Link :
https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
*/

class Solution
{
    private :
    void dfs(int node, vector<int> adj[],int visited[], stack<int>&st)
    {
        visited[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited,st);
            }
        }
        
        // First call DFS and then, push nodes into the stack
        st.push(node);
        return;
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Visited Array to keep a track of Visited Nodes
	    int visited[V] = {0};
	    // Stack to store topological sort
	    stack<int>st;
	    
	  for(int i=0; i<V; i++)
	  {
	      // If node is unvisited, call dfs 
	      if(visited[i]==0)
	      {
	          dfs(i,adj,visited,st);
	      }
	  }
	  
	  
	  vector<int>ans;
	  while(!st.empty())
	  {
	      ans.push_back(st.top());
	      st.pop();
	  }
	  return ans;
	  
	}
};
