// BIPARTITE GRAPH (BFS)

#include<bits/stdc++.h>
using namespace std;

bool bfs(int src,vector<int>adj[],int color[]){
    queue<int>q;
    q.push(src);
    color[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(int V,vector<int>adj[]){
    // COLOR ARRAY
    int color[V];
    memset(color,-1,sizeof color);
    for(int i=0;i<V;i++){
        if(color[i] == -1){
            if(!bfs(i,adj,color)){
                return false;
            }
        }
    }
    return true;
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
    cout<<checkBipartite(n,adj);
    return 0;
}