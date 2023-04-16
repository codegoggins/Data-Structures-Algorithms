// BIPARTITE GRAPH (DFS)
#include<bits/stdc++.h>
using namespace std;

bool bipartite(int node,vector<int> adj[],int color[]){

    if(color[node] == -1)color[node] = 1;

    // TRAVERSE ALL ADJACENT NODES OF NODE
    for(auto it:adj[node]){
        // IF ADJACENT NODE IS NOT COLORED
        if(color[it] != -1){
            color[it] = 1 - color[node];
            if(!bipartite(it,adj,color)){
                return false;
            }
        }else if(color[it] == color[node]){
            return false;
        }
    }
    return true;
}

bool checkBipartite(int V,vector<int>adj[]){
    int color[V];
    memset(color,-1,sizeof color);
    for(int i=0;i<V;i++){
        if(color[i] == -1){
            if(!bipartite(i,adj,color)){
                return false;
            }
        }
    }
    return true;
}


int main(){
int n,m;
cin>>n>>m;
vector<int>adj[n];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
cout<<checkBipartite(n,adj)<<endl;
return 0;
}