// Dijkstras using adj matrix graph

#include<bits/stdc++.h>
using namespace std;


vector<int> djikstras(int n, int adj[10][10], int src){
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     vector<int> v(n+1, INT_MAX);

     pq.push({0, src});
     v[src]=0;

     while(!pq.empty()){
          int dist=pq.top().first;
          int nd=pq.top().second;


          pq.pop();
          for(int i=0; i<n; ++i){
               if(adj[nd-1][i]){
                    if(dist+adj[nd-1][i]<v[i+1]){
                         v[i+1]=dist+adj[nd-1][i];
                         pq.push({v[i+1], i+1});
                    }
               }
          }
     }
     return v;
}

int main(){
     int n;
     cout<<"Enter the number of vertex in the graph: ";
     cin>>n;
     int adj[10][10];

     for(int i=0; i<n; ++i){
          for(int j=0; j<n; ++j){
               adj[i][j]=0;
          }
     }

     int e;
     cout<<"Enter the number of edges";
     cin>>e;

     while(e--){
          int x, y;
          cin>>x>>y;

          int w;
          cin>>w;

          adj[x-1][y-1]=w;
     }

     int src;
     cin>>src;

     vector<int> mndist=djikstras(n, adj, src);
     for(int i=1; i<=n; ++i){
          cout<<mndist[i]<<" ";
     }
}