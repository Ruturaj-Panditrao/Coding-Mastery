/*
Practice Link
https://leetcode.com/problems/flood-fill/
*/

class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&image, vector<vector<int>>&ans, int color, int initialColor)
    {
        // First we color the pixel, 
        ans[row][col] = color;

        // Now we look for its Neighbours.
        // Since Neighbours are to be looked in 4 Directions,
        // Row, Col+1
        // Row, Col-1
        // Row-1, Col
        // Row+1, Col

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // This is a Possible Neighbour Co-ordinate
            // We need to check whether it is a Valid Co-ordinate on the Grid
            // Also, it should be same as initial color of Starting Pixel
            // And, it should not have been touched yet in the Ans Grid
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor
            && ans[nrow][ncol]!= color)
            {
                dfs(nrow,ncol,image,ans,color,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        vector<vector<int>>ans = image;
        // Creating Copy of the Image

        int initialColor = image[sr][sc];
        // Original Color of the Starting Pixel

        dfs(sr,sc,image,ans,color,initialColor);
        // Calling the DFS function on the starting pixel
        return ans;

    }
};
