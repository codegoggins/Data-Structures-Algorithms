// CYCLE DETECTION IN DIRECTED GRAPH USING DFS

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node,vector<int>adj[],int visited[],int dfsVisited[]){
    visited[node] = 1;
    dfsVisited[node] = 1;

    for(auto it:adj[node]){
        if(!visited[it]){
            // NOT VISITED
            if(checkCycle(it,adj,visited,dfsVisited)){
                return true;
            }
        }else if(dfsVisited[it]){
            // IF VISITED AND ALSO DFS VISITED THEN RETURN TRUE
            return true;
        }
    }
    // REMOVE FROM DFS VISITED
    dfsVisited[node] = 0;
    return false;
}

bool isCyclic(int V,vector<int>adj[]){
     int visited[V],dfsVisited[V];
     memset(visited,0,sizeof visited);
     memset(dfsVisited,0,sizeof dfsVisited);

     for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkCycle(i,adj,visited,dfsVisited)){
                return true;
            }
        }
     }
     return false;
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<int>adj[n+1];

   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
   }

   cout<<isCyclic(n,adj)<<endl;
}