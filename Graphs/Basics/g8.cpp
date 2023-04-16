#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent,vector<int>&visited,vector<int> adj[]){
     visited[node] = 1;
     for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,node,visited,adj))return true;
        }else if(it != parent){
            return true;
        }
     }
     return false;
}

bool isCyclic(int V,vector<int> adj[]){
    vector<int>visited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
           if(dfs(i,-1,visited,adj))return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}