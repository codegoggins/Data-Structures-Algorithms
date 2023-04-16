// CYCLE DETECTION IN DIRECTED GRAPHS USING BFS (KAHN'S ALGORITHM)

/*

Topological Sort is only Possible in Directed Acyclic Graph
So if a linear ordering is possible then graph is acycic

*/

#include<bits/stdc++.h>
using namespace std;

bool cycleBFS(int V,vector<int>adj[]){
   
   queue<int>q;
   vector<int>indegree(V,0);
   for(int i=0;i<V;i++){
      for(auto it:adj[i]){
         indegree[it]++;
      }
   }
   for(int i=0;i<V;i++){
      if(indegree[i] == 0){
         q.push(i);
      }
   }
   int count = 0;
   while(!q.empty()){
      int node = q.front();
      q.pop();
      count++;
      for(auto it:adj[node]){
         indegree[it]--;
         if(indegree[it] == 0){
            q.push(it);
         }
      }

   }
   if(count == V)return false;

   return true;
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<int>adj[n+1];

   for(int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
   }

   cout<<cycleBFS(n,adj)<<endl;
}