/*
Practice Link
https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
*/

class Solution {
    
    private :
    
    void dfs(int row, int col, int newColor, int initialColor, vector<vector<int>>&ans,
    vector<vector<int>>&image)
    {
        // ans[row][col] = newColor;
        // We need to Move in 4 Directions
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        int n = ans.size();
        int m = ans[0].size();
        
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >=0 && nrow<n && ncol >=0 && ncol <m &&
            image[nrow][ncol]==initialColor && ans[nrow][ncol]!=newColor)
            {
                ans[nrow][ncol] = newColor;
                dfs(nrow,ncol,newColor,initialColor,ans,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<int>>ans = image;
        int initialColor = image[sr][sc];
        ans[sr][sc] = newColor;
        dfs(sr,sc,newColor,initialColor,ans,image);
        return ans;
    }
};
