/*
Practice Link
https://practice.geeksforgeeks.org/problems/graph-and-vertices/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=graph-and-vertices
*/

class Solution {
  public:
    long long count(int n) 
    {
        
        long long int m = (n*(n-1))/2;
        return pow(2,m);
        // Standard Result
        // For n number of vertices,
        // The Total Possible Number of Undirected Graphs,
        // is 2^((n)*(n-1)/2)
    }
};
