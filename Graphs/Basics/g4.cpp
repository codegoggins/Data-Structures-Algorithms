// WEIGHTED UNDIRECTED GRAPH

#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
   cin>>n>>m;

  //  ADJACENCY LIST CONTAINS PAIRS OF ADJACNET NODE AND WIGHT OF EGDE
   vector<pair<int,int>> adj[n+1];

   for(int i=0;i<m;i++){
     int u,v,wt;
     cin>>u>>v>>wt;
     adj[u].push_back({v,wt});
     adj[v].push_back({u,wt});
   }
   return 0;
}