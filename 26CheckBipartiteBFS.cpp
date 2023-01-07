/*
Practice Link
https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
*/

class Solution
{

private :
bool checkBipartite(int node, vector<int>adj[], int colour[])
{
    colour[node] = 0;
    queue<int>q;
    q.push(node);
    
    while(!q.empty())
    {
        int curnode = q.front();
        q.pop();
        
        for(auto it : adj[curnode])
        {
            // If the adjacent node has not been coloured,
            // Colour it with the Opposite Colour
            
            if(colour[it]==-1)
            {
                colour[it]=!colour[curnode];
                // Push it onto the Queue
                q.push(it);
            }
            
            // If the adjacent node has already been coloured,
            // Check if it has the right colour
            // If the current node & the adjacent node have the same colour
            // Then return false and exit, the graph is not bipartite
            
            if(colour[it]==colour[curnode])
            {
                return false;
            }
        }
    }
    
    // If the entire Traversal has been Completed till here
    // It means that the Graph is Bipartite
    return true;
}
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    // Colour Matrix
	    int colour[V];
	    for(int i=0; i<V; i++)
	    {
	        colour[i] = -1;
	        // Initially, mark all Nodes as Uncoloured
	    }
	    
	    // Call the checkBipartite() function over all Components
	    // To make sure to cover Connected Components
	    
	    for(int i=0; i<V; i++)
	    {
	        if(colour[i]==-1)
	        {
	            if(checkBipartite(i,adj,colour)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};
