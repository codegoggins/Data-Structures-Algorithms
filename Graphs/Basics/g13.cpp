// TOPOLOGICAL SORT (DFS)

/*
Topological sort is a linear ordering of the vertices of a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. In other words, it is an ordering of the vertices that respects the partial order defined by the directed edges of the graph.

Topological sort is commonly used in graphs that represent dependencies or precedence relationships between tasks, where some tasks must be completed before others can start. For example, in project scheduling, where tasks have dependencies and must be completed in a certain order, topological sort can be used to determine a valid schedule that satisfies the dependencies. Other applications of topological sort include scheduling courses with prerequisites in a curriculum, determining the order of compilation of source code files with dependencies, and finding a valid sequence of courses to take in a curriculum with prerequisites.

Topological sort has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges in the graph. It can be performed using various algorithms, such as depth-first search (DFS) or breadth-first search (BFS), and it can also be used to detect cycles in a graph. If a graph has a valid topological sort, it is a directed acyclic graph (DAG); otherwise, it contains at least one cycle.

Linear Oredering of vertices such that if there is an edge u->v , u appears before v in that ordering.

A graph can have multiple Topological Sorts

Topological Sorting is only Possible For Directed Acyclic Graphs

Topological Sort is NOT possible in a Cyclic Graph

*/

#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node,vector<int>adj[],vector<int>visited,stack<int>st){
     visited[node] = 1;
     for(auto it:adj[node]){
        if(!visited[it]){
            findTopoSort(it,adj,visited,st);
        }
     }
     st.push(node);
}

vector<int> topoSort(int V,vector<int> adj[]){
   stack<int>st;
   vector<int>visited(V,0);
   for(int i=0;i<V;i++){
      if(!visited[i]){
        findTopoSort(i,adj,visited,st);
      }
   }
   vector<int>topo;
   while(!st.empty()){
     topo.push_back(st.top());
     st.pop();
   }
   return topo;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>ans = topoSort(n,adj);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}