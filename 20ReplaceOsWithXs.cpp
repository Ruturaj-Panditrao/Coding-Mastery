/*
Practice Link
https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs
*/

class Solution{

private :

void dfs(int row, int col,vector<vector<char>>&mat,vector<vector<int>>&visited,int delrow[], int delcol[])
{
    int n = mat.size();
    int m = mat[0].size();
    
    visited[row][col] = 1;
    
    // Explore the Neighbours
    
    for(int i=0; i<4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && visited[nrow][ncol]==0
        && mat[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,mat,visited,delrow,delcol);
        }
    }
    return;
}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // Question Says 'Replace'
        // So we replace inplace,
        // And do not create a Answer Matrix
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        // Explore all the Boundaries
        // Top region -> Row 0, Col 1,2,3,4..m
        // Bottom region -> Row n-1, Col 1,2,3,4..m
        // Left region -> Row 1,2,3,4..n Col = 0
        // Right region -> Row 1,2,3,4..n Col = m-1
        
        for(int i=0; i<m; i++)
        {
            // Explore the topmost Row
            if(visited[0][i]==0 && mat[0][i]=='O')
            {
                dfs(0,i,mat,visited,delrow,delcol);
            }
            // Explore the Bottommost Row
            if(visited[n-1][i]==0 && mat[n-1][i]=='O')
            {
                dfs(n-1,i,mat,visited,delrow,delcol);
            }
        }
        
        for(int i=0; i<n; i++)
        {
             // Explore the leftmost Column
            if(visited[i][0]==0 && mat[i][0]=='O')
            {
                dfs(i,0,mat,visited,delrow,delcol);
            }
            // Explore the Rightmost Column
            if(visited[i][m-1]==0 && mat[i][m-1]=='O')
            {
                dfs(i,m-1,mat,visited,delrow,delcol);
            }
        }
        
        // Now every O at the border and its touching Os have been
        // Marked as Visited 
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]=='O' && visited[i][j]==0)
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
