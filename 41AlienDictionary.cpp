/*
Practice Link
https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
*/

class Solution
{ 
    private :
    vector<int> topoSort(int V, vector<int>adj[])
    {
        int indegree[V] ={0};
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>topo;
        
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K)
    {
        // Adjacency Matrix
        vector<int>adj[K];
        
        for(int i=0; i<N-1;i++)
        {
            // First Word
            string s1 = dict[i];
            // Second Word
            string s2 = dict[i+1];
            
            int commonlen = min(s1.length(),s2.length());
            
            for(int ptr =0; ptr<commonlen; ptr++)
            {
                if(s1[ptr]!=s2[ptr])
                {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    // Add edge to the Number Based Graph
                    // Subtract a to convert char to integer
                    break;
                }
            }
        }
        
        vector<int>topo = topoSort(K,adj);
        
        string answer = "";
        
        for(auto it : topo)
        {
            answer+=(it+'a');
            // Add a to convert number back to character
        }
        
        return answer;
    }
};
