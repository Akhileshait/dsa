#include<bits/stdc++.h>
using namespace std;

bool vis[10]={0};
void topSort(int k, int adj[10][10], stack<int> &s, int n){
     vis[k]=1;
     for(int i=0; i<n; ++i){
          if(adj[k][i] && !vis[i]){
               topSort(i, adj, s, n);
          }
     }
     s.push(k);
}

int main(){
     int n;
	cout<<"Enter the vertex: ";
	cin>>n;

	int adj[10][10];
	int topo[n] = {0};
	
	for (int i = 0; i< n; i++){
		for (int j = 0; j < n; j++){
			adj[i][j] = 0;
                }
        }
	
	int e;
     cout<<"Enter the number of edges";
     cin>>e;

     while(e--){
          int x, y;
          cin>>x>>y;
          adj[x][y]=1;
     }

     stack<int> st;
     for(int i=0; i<n; ++i){
          if(!vis[i]){
               topSort(i, adj, st, n);
          }
     }
     while(!st.empty()){
          cout<<st.top()<<" ";
          st.pop();
     }

}