/*
Practice Link :
https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
*/

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites)
	{
	  // Construct Graph
	  vector<int>adj[N];
	  for(auto it : prerequisites)
	  {
	      adj[it.second].push_back(it.first);
	  }
	  
	  // Indegree Array
	  int indegree[N] = {0};
	  
	  // Construct Indegree Array
	  
	  for(int i=0; i<N; i++)
	  {
	      for(auto it : adj[i])
	      {
	          indegree[it]++;
	      }
	  }
	  
	  // Queue
	  queue<int>q;
	  
	  // Fill the Queue with Nodes having Indegree 0
	  
	  for(int i=0; i<N; i++)
	  {
	      if(indegree[i]==0) q.push(i);
	  }
	  
	  vector<int>topoSort;
	  // Vector that Contains Topo Sort (if possible)
	  while(!q.empty())
	  {
	      int node = q.front();
	      topoSort.push_back(node);
	      q.pop();
	      
         for(auto it : adj[node])
         {
             indegree[it]--;
             if(indegree[it]==0) q.push(it);
         }
	  }
	  
	  if(topoSort.size()==N) return true;
	  else return false;
	}
};
