// CYCLE DETECTION IN GRAPHS

/*
--> If a graph has multiple components , then even if one component has a cycle then the graph is cyclic
--> We will do a BFS traversal here as well
--> We will visit nodes one by one and add them in the queue
--> If the node has already been visited it means there exists a cycle
--> But when we visit a node , the prev node is also in adjacency list which is marked visited , but it does not means that a cycle is formed
--> So we insert in queue the current node in list and previous node
--> If the current node in list is visited and it is also prev then we don't return false
*/

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int s,int V,vector<int>adj[],vector<int>&visited){

    // create queue for BFS
    queue<pair<int,int>>q;
    visited[s] = true;
    q.push({s,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // traverse for all its adjacent nodes
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it,node});  
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(int V,vector<int>adj[]){
    vector<int>visited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(checkCycle(i,V,adj,visited)){
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
     adj[v].push_back(u);
    }
    cout<<isCyclic(n,adj);
    return 0;    
}