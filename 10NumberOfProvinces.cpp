/*
Practice Link
https://leetcode.com/problems/number-of-provinces/description/
*/

class Solution {
public:

    void dfs(int node, vector<bool>&visited,vector<vector<int>>&isConnected)
    {
        visited[node] = true;
        for(int it =0; it<isConnected[node].size();it++)
        {
            if(visited[it]==false && isConnected[node][it]==1)
            {
                dfs(it,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int counter = 0;
        vector<bool>visited(isConnected.size(),false);
        for(int i=0; i<isConnected.size(); i++)
        {
            if(visited[i]==false)
            {
                dfs(i,visited,isConnected);
                counter++;
            }
        }
        return counter;
    }
};
