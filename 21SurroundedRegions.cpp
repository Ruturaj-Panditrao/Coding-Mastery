/*
Practice Link 
https://leetcode.com/problems/surrounded-regions/description/
*/

class Solution 
{
private :

void dfs(int row, int col, vector<vector<char>>&board,
 vector<vector<int>>&visited,int delrow[],int delcol[])
{
    int n = board.size();
    int m = board[0].size();

    visited[row][col] = 1;
    // Mark it as Visited as it as a Boundary O
    // Now explore the Neighbours of this O,
    // In 4 Directions -> Top, Bottom, Left, Right

    for(int i=0; i<4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // Check if the Neighbour Co-ordinates are Valid (Within the Board)
        // Also, if the Neighbour is an 'O'
        // And if it has not been Visited Yet
        if(nrow >=0 && nrow<n  && ncol >=0 && ncol<m && 
        board[nrow][ncol]=='O' && visited[nrow][ncol]==0)
        {
            dfs(nrow,ncol,board,visited,delrow,delcol);
        }
    }
    return;
}
public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        // Visited
        vector<vector<int>>visited(n,vector<int>(m,0));

        int delrow [] = {-1,0,1,0};
        int delcol [] = {0,1,0,-1};

        // Explore the Boundary Os
        for(int i=0; i<n; i++)
        {
            // Varying Row, Same Columm

            // Leftmost Boundary Column Number 0
            if(board[i][0]=='O' && visited[i][0]==0)
            {
                dfs(i,0,board,visited,delrow,delcol);
            }

            // Rightmost Boundary Column Number m-1
            if(board[i][m-1]=='O' && visited[i][m-1]==0)
            {
                dfs(i,m-1,board,visited,delrow,delcol);
            }
        }

        for(int i=0; i<m; i++)
        {
            // Varying Column, Fixed Row

            // Topmost Boundary Row Number 0
            if(board[0][i]=='O' && visited[0][i]==0)
            {
                dfs(0,i,board,visited,delrow,delcol);
            } 

            // Bottom-Most Boundary Row Number n-1
            if(board[n-1][i]=='O' && visited[n-1][i]==0)
            {
                dfs(n-1,i,board,visited,delrow,delcol);
            }
        }

        // Now we have marked all the Os on the Boundaries,
        // As well as the Os that touch the Boundary Os
        // These are not surrounded by Xs (since on Boundary or are surrounded by Os)
        // Hence all the Os except the ones marked as Visited will be converted to Xs

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O' && visited[i][j]==0)
                {
                    // If it is an 'O',
                    // And it has not been marked on visited
                    // Convert it into an X
                    board[i][j]='X';
                }
            }
        }
    }
};
