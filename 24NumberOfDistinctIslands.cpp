/*
Practice Link
https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

class Solution 
{
    
private :
    void dfs(int row,int col, vector<vector<int>>&visited, vector<vector<int>>&grid,
    int row0, int col0, vector<pair<int,int>>&temp)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        visited[row][col] = 1;
        
        temp.push_back({row-row0,col-col0});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0
            && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,visited,grid,row0,col0,temp);
            }
        }
        return;
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        // Visited Grid
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>s;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    vector<pair<int,int>>temp;
                    // Co-ordinates,Vis,Grid,Base Co-ordinates
                    dfs(i,j,visited,grid,i,j,temp);
                    s.insert(temp);
                }
            }
        }
        
        return s.size();
    }
};
