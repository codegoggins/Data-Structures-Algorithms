// DFS TRAVERSAL
#include<bits/stdc++.h>
using namespace std;

void traversal(int node,vector<int>&visited,vector<int>adj[],vector<int>&dfs){
     dfs.push_back(node);
     visited[node]=1;
     for(auto it:adj[node]){
        if(!visited[it]){
            traversal(it,visited,adj,dfs);
        }
     }
}


vector<int> DFS(int V,vector<int>adj[]){
    vector<int>dfs;
    vector<int>visited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            traversal(i,visited,adj,dfs);
        }
    }
    return dfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>ans = DFS(n,adj);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

// n = 7 m = 6

// 1 2
// 2 7
// 2 4
// 4 6
// 6 7
// 3 5

// DFS = 1 2 7 6 4 3 5 