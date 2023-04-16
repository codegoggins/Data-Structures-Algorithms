// BFS TRAVERSAL
#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int V,vector<int> adj[]){
    // STORE THE TRAVERSAL HERE
    vector<int>bfs;
    // VISITED VECTOR
    vector<int>visited(V+1,0);

    for(int i=1;i<=V;i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                // ADD ALL THE ADJACENT NODES
                // adj[node] -> is a vector
                // so it will be element in that vector
                for(auto it:adj[node]){
                    if(!visited[it]){ 
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
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
   vector<int>ans = BFS(n,adj);
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
   return 0;
}

// n=7 m=6


// 1 2
// 2 3
// 2 7
// 3 5
// 5 7
// 4 6

// BFS = 1 2 3 7 5 4 6