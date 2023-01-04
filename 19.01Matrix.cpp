/*
Practice Link
https://leetcode.com/problems/01-matrix/description/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
     // Visited Array to Keep a Track of Visited Vertices
     vector<vector<int>>visited(n,vector<int>(m,0));
     // Answer Matrix to Store the Final Answer
     vector<vector<int>>ansmat(n,vector<int>(m,0));

    // Queue 
    // It is of the type (row,col),steps
    queue<pair<pair<int,int>,int>>q;

     for(int i=0; i<n; i++)
     {
         for(int j=0; j<m; j++)
         {
             if(mat[i][j]==0)
             {
                 // Locate all the Zeroes
                 // These Zeroes are at a Distance of 0 from Nearest Zero
                 // This is because they themselves are Zeroes
                 // Hence (row,col),0
                 q.push({{i,j},0});
                 visited[i][j] = 1;
             }
             else
             {
                 visited[i][j] = 0;
             }
         }
     }   

    // Standard BFS Approach
     while(!q.empty())
     {
         int r = q.front().first.first;
         int c = q.front().first.second;
         int steps = q.front().second;

            ansmat[r][c] = steps;
         q.pop();

         int delrow [] = {-1,0,1,0};
         int delcol [] = {0,1,0,-1};

        // Explore all the Neigbours in 4 Directions
        // Up -> row-1,col
        // Down -> row+1,col
        // Left -> row,col-1
        // Right -> row,col+1

         for(int i=0; i<4; i++)
         {
             int nrow = r + delrow[i];
             int ncol = c + delcol[i];

             if(nrow >=0 && nrow <n && ncol >=0 && ncol<m && visited[nrow][ncol]==0)
             {
                 // Since we are 1 step away than previous, steps+1
                 q.push({{nrow,ncol},steps+1});
                 visited[nrow][ncol] = 1;
             }
         }
     }
    
    // Return the Final Answer Matrix
     return ansmat;
    }
};
