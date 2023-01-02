/*
Practice Link :
https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int totalrows = grid.size(); // Total Rows
        int totalcols = grid[0].size(); // Total Columns

        vector<vector<int>>gridcopy = grid;
        // gridcopy is the copy of the Original Grid
        // We will work on this copy,
        // As I prefer not tampering the original given data

        // Since the Oranges Rot in a Spread-Out Fashion,
        // The Oranges simultaneously rot all neighbouring fresh oranges
        // Hence the Algorithm we will use is BFS 

        queue<pair<pair<int,int>,int>>q;
        // Our Queue Data Structure is of the type
        // (row,col),time

        for(int i=0; i<totalrows; i++)
        {
            for(int j=0; j<totalcols; j++)
            {
                if(gridcopy[i][j]==2)
                {
                    q.push({{i,j},0});
                    // These are the first set of Rotten Oranges
                    // Hence, these are the ones at t=0
                }
            }
        }

        int time = 0; // This is the time variable to be returned as final answer

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            time = max(t,time);
            // To keep track of the Maximum Time 
            q.pop();

            // Since we need to check adjacent neighbours in 4 directions,
            // For a particular (row,col)
            // We need to check
            // (row,col-1)
            // (row,col+1)
            // (row-1,col)
            // (row+1,col)
            // These co-ordinates

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};

            for(int i=0; i<4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                // Here (nrow,ncol) are the neighbour co-ordinates
                // We also need to check whether 
                // this adjacent is a valid Grid co-ordinate
                // also, whether it is fresh orange or not

                if(nrow>=0 && nrow<totalrows && ncol>=0 && ncol<totalcols && gridcopy[nrow][ncol]==1)
                {
                    // This co-ordinate is a valid one (that is, it lies within the Grid)
                    // Also, it is a Fresh Orange

                    gridcopy[nrow][ncol]=2; // Rot the Orange
                    q.push({{nrow,ncol},t+1}); // Push it into the queue, 
                    // So that we can explore its neighbours later
                    // Time would be t+1, because these oranges would be doing their work after 1 second,
                    // That is after the current set of rotten have done their work
                }
            }

           
           
        }

        // We traverse the Grid one last time to see if any fresh orange is still left
        // If a fresh orange is still left,
        // It means we could not rot all the fresh oranges
        // And the answer is -1

        // Alternatively, we could also have kept a track of number of fresh oranges
        // in the beginning, and each time we rot a fresh orange,
        // we can decrement that count
        // If count of fresh oranges becomes 0, we return time
        // If still fresh oranges are left, we return -1
        
         for(int i=0; i<totalrows; i++)
            {
                for(int j=0; j<totalcols; j++)
                {
                    if(gridcopy[i][j]==1)
                    {
                        time = -1;
                        break;
                    }
                }
            }

            return time;

    }
};
