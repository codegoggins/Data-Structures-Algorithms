// TOPOLOGICAL SORT (BFS)

#include<bits/stdc++.h>
using namespace std;



vector<int> topoSort(int V,vector<int> adj[]){
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
  vector<int>topo;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it] == 0){
            q.push(it);
        }
    }
  }
  return topo;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>ans = topoSort(n,adj);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}