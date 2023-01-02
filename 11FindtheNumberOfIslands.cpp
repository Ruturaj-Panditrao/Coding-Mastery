/*
Practice Link
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
*/

class Solution {
  public:
    // Function to find the number of islands.
    
    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<char>>&visited)
    {
        visited[row][col] = '1';
        queue<pair<int,int>>q;
        q.push({row,col});
        
        int n = grid.size();
        int m =grid[0].size();
        
        while(!q.empty())
        {
            int tr = q.front().first;
            int tc = q.front().second;
            
            q.pop();
            
            // All 8 Directions to Be Explored for the Neighbours
            
            for(int delrow =-1; delrow<=1; delrow++)
            {
                for(int delcol = -1; delcol<=1; delcol++)
                {
                    int nrow = tr + delrow;
                    int ncol = tc + delcol;
                    
                    if(nrow >=0 && nrow <n && ncol >=0 && ncol <m 
                    && grid[nrow][ncol]=='1' && visited[nrow][ncol]=='0')
                    {
                        visited[nrow][ncol] = '1';
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<char>>visited(rows,vector<char>(cols,'0'));
        
        int counter = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j]=='1' && visited[i][j]=='0')
                {
                    bfs(i,j,grid,visited);
                    counter+=1;
                }
            }
        }
        return counter;
    }
};
