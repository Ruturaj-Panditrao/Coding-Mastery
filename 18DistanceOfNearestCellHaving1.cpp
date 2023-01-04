/*
Practice Link
https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having
*/

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(); //rows
	    int m =  grid[0].size(); //cols
	    // Answer Grid
	    // Vector of Vectors
	    // vector<vector<int>>
	    // Of length n,
	    // Initialized with m entries of 0
	    vector<vector<int>>ansGrid(n,vector<int>(m,0));
	    // Visited Grid
	    vector<vector<int>>visited(n,vector<int>(m,0));
	    
	    // Queue
	    // Queue contains (rol,col),steps

	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                // Cell having 1 
	                // Is at a distance of 0
	                // From nearest cell having 1
	                visited[i][j] = 1;
	            }
	            else
	            {
	                visited[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c =  q.front().first.second;
	        int steps =  q.front().second;
	        
	        ansGrid[r][c] = steps;
	        q.pop();
	        
	        // Explore 4 directions
	        // Up, down, right left
	        int delrow[] = {-1,0,1,0};
	        int delcol[] = {0,1,0,-1};
	        
	        for(int i=0; i<4; i++)
	        {
	            int nrow = r + delrow[i];
	            int ncol = c + delcol[i];
	            
	            // Check is these Possible Neighbour Co-ordinates are Valid
	            // Also, they need to be zeroes
	            // Also, they need to be unvisited
	            if(nrow>=0 && nrow<n && ncol >=0 && ncol <m 
	            && visited[nrow][ncol]==0)
	            {
	                q.push({{nrow,ncol},steps+1});
	                visited[nrow][ncol] = 1;
	            }
	        }
	    }
	      return ansGrid;
	}
};
