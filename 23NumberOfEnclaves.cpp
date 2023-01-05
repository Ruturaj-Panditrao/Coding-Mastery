/*
Practice Link
https://leetcode.com/problems/number-of-enclaves/description/
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        // Rows
        int n = grid.size();
        // Columns
        int m = grid[0].size();

        // Visited Grid
        vector<vector<int>>visited(n,vector<int>(m,0));

        // Queue Data Structure
        queue<pair<int,int>>q;
        // Our queue contains (row,column) pair of the cell

        // Locate all the Boundary 1s
        // And push them into the queue
        // Boundaries are extreme left, right, top and bottom
        // For the uppermost boundary, row = 0, col = 1,2,..m
        // For the lowermost boundary, row = n-1 , col = 1,2,..m
        // For the leftmost boundary, row = 1,2,..n , col = 0
        // For the rightmost boundary, row = 1,2,..n , col = m-1
        // Push these into the queue

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

        // BFS (Breadth First Traversal Approach)

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Now, explore neighbours of this cell in 4 directions
            // Up -> r-1,c
            // Down -> r+1,c
            // Left -> r,c-1
            // Right -> r,c+1
            // Doing this using delrow and delcol created above,
            // Could also be typed manually.

            for(int i=0; i<4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                // Check whether the neighbour co-ordinates are valid
                // Check if the neighbour is a 1
                // Also, check whether it has already been visited
                // If favourable cell , mark it as visited and push it onto the queue
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol]==1 && visited[nrow][ncol]==0)
                {
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        // Now, our visited contains the information about 1s 
        // That are either on boundaries, or connected to boundaries
        // All the other 1s in the grid apart from these are enclaves
        // Traverse and count them up

        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    count++;
                }
            }
        }

        // Return count answer
        return count;
    }
};
