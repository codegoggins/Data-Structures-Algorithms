// DIJKSTRA's ALGORITHM

#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,m,src;
   cin>>n>>m>>src;
   //1 indexed adjacency list for graph
   vector<pair<int,int>>adj[n+1];

   int u,v,wt;
   for(int i=0;i<m;i++){
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});
   }

   // PRIORITY QUEUE 
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

   //DISTANCE ARRAY
   vector<int>distTo(n+1,INT_MAX);
   distTo[src] = 0;
//    dist(distance,from)
   pq.push(make_pair(0,src));

   while(!pq.empty()){
     int dist = pq.top().first;
     int prev = pq.top().second;
     pq.pop();

     vector<pair<int,int>>::iterator it;
     for(it = adj[prev].begin();it!=adj[prev].end();it++){
        int next = it->first;
        int nextDist = it->second;

        if(distTo[next] > distTo[prev] + nextDist){
              distTo[next] = distTo[prev] + nextDist;
              pq.push(make_pair(distTo[next],next));
        }
     }
   }

   cout<<"The distances from source "<<src<<" , are : "<<endl;
   for(int i=1;i<=n;i++){
      cout<<distTo[i]<<" ";
   }
}