// SHORTEST PATH IN DIRECTED ACYCLIC WEIGHTED GRAPH
#include<bits/stdc++.h>
using namespace std;

/*
WHY DO WE USE TOPOLOGICAL SORT HERE ?

Processing the vertices in topological order ensures that by the time you get to a vertex, you’ve already processed all the vertices that can precede it which reduces the computation time significantly.

Dijkstra’s algorithm is necessary for graphs that can contain cycles because they can’t be topologically sorted. In other cases, the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.

*/ 

void topoSort(int node,int visited[],stack<int>st,vector<pair<int,int>>adj[]){
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it.first]){
             topoSort(it.first,visited,st,adj);
        }
    }
    st.push(node);
}

void shortestPath(int src,int V,vector<pair<int,int>>adj[]){
    int visited[V] ={0};
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topoSort(i,visited,st,adj);
        }
    }
    int dist[V];
    dist[src] = 0;
    for(int i=1;i<V;i++){
        dist[i] = INT_MAX;
    }

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it:adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        if(dist[i] == INT_MAX){
            cout<<"INF"<<" ";
        }else{
            cout<<dist[i]<<" ";
        }
    }
}

int main(){
 int n,m;
 cin>>n>>m;
 vector<pair<int,int>>adj[n];

 for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
 }
 shortestPath(0,n,adj);
}