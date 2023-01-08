/*
Practice Link
https://leetcode.com/problems/is-graph-bipartite/description/
*/

class Solution 
{
private :
    bool dfsCheck(int node, vector<vector<int>>&graph, int col,int colour[])
    {
        // Mark the Current Node with Colour
        colour[node] = col;

        // Now we move to its Adjacency List
        // If we find a neighbouring node uncoloured,
        // We give it a colour opposite to the Current Node's Colour

        for(auto it : graph[node])
        {
            if(colour[it]==-1)
            {
                // Colour it with Opposite Colour & pass it for further DFS calls
                if(dfsCheck(it,graph,!col,colour)==false)
                {
                    return false;
                }
            }
            if(colour[it]==col)
            {
                // If the Adjacent Node has the Same Colour as the Current Node
                // Then Conflicting Colours are side by side
                // And the Graph is not Bipartite
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        // Finding the Number of Vertices
        int V = graph.size();
        // Colour Array 
        int colour[V];
        for(int i=0; i<V; i++)
        {
            colour[i] = -1;
            // Initializing all the Nodes as Uncoloured
        }

        // Dfs Approach
        // Since it is mentioned that all the Nodes may not be connected,
        // That is, there can be isolated components,
        // We run this for loop to make sure all the Nodes are Visited

        // Default colour to start exploring any component be set to 0,
      
        for(int i=0; i<V;i++)
        {
            if(colour[i]==-1)
            {
                if(dfsCheck(i,graph,0,colour)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
