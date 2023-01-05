/*
Practice Link
https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
*/

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // Visited
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        queue<pair<int,int>>q;
        
        // Push all the Boundary 1s to the Queue
        // Mark them as visited
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
        
        // Declare delrow & delcol here
        // Else they get created each time queue loop runs
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            // Now explore Neighbours of these boundary 1s
            
            for(int i=0; i<4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0
                && grid[nrow][ncol]==1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        long long int counter=0;
        
        // All the Grid 1s which have not been marked in Visited Array
        // Are the Enclaves
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    counter++;
                }
            }
        }
        
        return counter;
        
        
    }
};
