#include<bits/stdc++.h>
using namespace std;


vector<int> djikstras(int V, vector<pair<int, int>> adj[], int src){
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     vector<int> dist(V, INT_MAX);
     dist[src]=0;
     pq.push({0, src});

     while(!pq.empty()){
               int distance=pq.top().first;
               int node=pq.top().second;
               pq.pop();
               for(auto k:adj[node]){
                    int weight=k.second;
                    int adjnode=k.first;
                    if(distance+weight<dist[adjnode]){
                         dist[adjnode]=distance+weight;
                         pq.push({dist[adjnode], adjnode});
                    }
               }
     }
     return dist;
}

int main(){
     int n;
     cout<<"Enter the number of vertex in the graph: ";
     cin>>n;
     vector<pair<int, int>> adj[n+1];
     for(int i=1; i<=n; ++i){
          int k;
          cin>>k;
          while(k){
               int v, w;
               cin>>v;
               cin>>w;
               adj[i].push_back(make_pair(v, w));
          }
     }

     vector<int> ans=djikstras(n, adj, 0);




}