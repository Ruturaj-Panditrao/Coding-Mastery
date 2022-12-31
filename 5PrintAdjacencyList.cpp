/*
Practice Link
https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list
*/

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Adj is the Adjacency List
        // It is an Array of Vectors
        // Each index of Adj is a Vector
        // And each index is a node 
        // And all its neighbours are in the corresponding vector
        // Expected Result is the same,
        // Vector of Vectors
        // Each index of vector corresponds to a node
        // And the node has its corresponding vector of neighbours
        // We need the Neighbours in Sorted Order
        
        vector<vector<int>>ans;
        
        for(int i=0; i<V; i++)
        {
            vector<int>neighbours = adj[i];
            sort(neighbours.begin(),neighbours.end());
            neighbours.insert(neighbours.begin(),i);
            ans.push_back(neighbours);
        }
        return ans;
    }
};
