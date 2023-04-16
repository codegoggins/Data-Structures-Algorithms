#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<int>adj[],int V,int src){
   int dist[V];
   for(int i=0;i<V;i++){
    dist[i] = INT_MAX;
   }
   queue<int>q;
   dist[src] = 0;
   q.push(src);

   while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it:adj[node]){
            if(1+dist[node] < dist[it]){
                dist[it] = 1+dist[node];
                q.push(it);
            }
        }
   }
   for(int i=0;i<V;i++){
    cout<<dist[i]<<" ";
   }
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
    int src = 0;
    shortestPath(adj,n,src);

    return 0;
}