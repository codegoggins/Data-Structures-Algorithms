// TOPOLOGICAL SORT (DFS)

/*

Linear Oredering of vertices such that if there is an edge u->v , u appears before v in that ordering.

A graph can have multiple Topological Sorts

Topological Sorting is only Possible For Directed Acyclic Graphs

Topological Sort is NOT possible in a Cyclic Graph

*/

#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node,vector<int>adj[],vector<int>visited,stack<int>st){
     visited[node] = 1;
     for(auto it:adj[node]){
        if(!visited[it]){
            findTopoSort(it,adj,visited,st);
        }
     }
     st.push(node);
}

vector<int> topoSort(int V,vector<int> adj[]){
   stack<int>st;
   vector<int>visited(V,0);
   for(int i=0;i<V;i++){
      if(!visited[i]){
        findTopoSort(i,adj,visited,st);
      }
   }
   vector<int>topo;
   while(!st.empty()){
     topo.push_back(st.top());
     st.pop();
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