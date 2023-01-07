/*
Practice Link
https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
*/

class Solution 
{
private :

bool dfs(int node, int col, int colour[], vector<int>adj[])
{
    colour[node] = col;
    // Colour the Node with the Given Colour
    
    for(auto it : adj[node])
    {
        if(colour[it]==-1)
        {
            // If the Node is Uncoloured,
            // Pass it to further dfs with Opposite Colour
            if(dfs(it,!col,colour,adj)==false)
            {
                return false;
            }
        }
        
        // If the Node is already coloured
        // If the colour of the node is same as the current Node
        // Return false,as the Graph is not Bipartite
        
        if(colour[it]==col)
        {
            return false;
        }
    }
    
    return true;
}
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    // Colour Array
	    int colour[V];
	    for(int i=0; i<V; i++)
	    {
	        colour[i] = -1;
	        // Initially Mark all the Nodes as Uncoloured
	    }
	    
	    // To make sure all the Components are Traversed
	    
	    for(int i=0; i<V; i++)
	    {
	        if(colour[i]==-1)
	        {
	            if(dfs(i,0,colour,adj)==false)
	            {
	                // If any component Returns false,
	                // Then simply return false and exit
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};
