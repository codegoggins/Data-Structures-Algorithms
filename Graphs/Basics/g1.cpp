// STORING GRAPHS IN DATA STRUCTURES

// ADJACENCY MATRIX

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    // n = Number of Nodes
    // m = Number of Edges
    cin>>n>>m;

    // 1 Based Indexing Nodes
    int adj[n+1][m+1];
    
    // Take Edges As Input
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}