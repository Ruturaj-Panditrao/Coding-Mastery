/*
Practice Link
https://practice.geeksforgeeks.org/problems/alone-in-couple5507/1?page=1&difficulty[]=-2&status[]=solved&sortBy=submissions
*/

class Solution{
    public:
    int findSingle(int N, int arr[])
    {
        int x = arr[0];
        for(int i=1; i<N;i++)
        {
            x^=arr[i];
        }
        return x;
        
        // Approach 1
        // Nested Loop 
        // TC : O(N^2) and SC : O(1)
        
        // Approach 2
        // Using Unordered Set
        // TC : O(N) and SC : O(N)
        
        // Approach 3
        // By XOR Operation
        // TC : O(N) and SC : O(1)
        
    }
};
