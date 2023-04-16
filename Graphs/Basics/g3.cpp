// DIRECTED GRAPHS using Adjacency List

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

//  ADJACENCY LIST
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    return 0;
}