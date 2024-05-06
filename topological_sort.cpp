#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;

     vector<int> adj[n+1];
     for(int i=1; i<=n; ++i){
          int k;
          cin>>k;
          while(k){
               int v;
               cin>>v;
               adj[i].push_back(v);
               k--;
          }
     }

     int ideg[n+1]={0};
     for(int i=1; i<=n; ++i){
          for(int j=0; j<adj[i].size(); ++j){
               ideg[adj[i][j]]++;
          }
     }

     queue<int> q;
     for(int i=1; i<=n; ++i){
          if(ideg[i]==0){
               q.push(i);
          }
     }
     
     vector<int> topologicalOrder;
     while(!q.empty()){
          int x=q.front();

          q.pop();
          topologicalOrder.push_back(x);

          for(int i=0; i<adj[x].size(); ++i){
               ideg[adj[x][i]]--;
               if(ideg[adj[x][i]]==0){
                    q.push(adj[x][i]);
               }
          }

     }
}