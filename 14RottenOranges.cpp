/*
Practice Link
https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges
*/

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>>gridcp = grid;
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    // These are the Initial Rotten Oranges
                    // All will start Rotting at 0
                }
            }
        }
        
        int time = 0;
        // BFS Traversal 
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            
            time = max(t,time);
            q.pop();
            
            // Check up,down,left,right
            
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                // Check whether Valid
                // Check Whether it is Fresh
                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols &&
                gridcp[nrow][ncol]==1)
                {
                    gridcp[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(gridcp[i][j]==1) return -1;
            }
        }
        
        return time;
    }
};
