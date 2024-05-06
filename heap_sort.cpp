//Akhilesh Patidar
//Roll no. 7207
//Comp B


#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int> &a, int i, int n){
     if(i>n/2)return;

     int max=i;
     if(2*i<=n && a[2*i]>a[max]){
          max=2*i;
     }
     if(2*i+1<=n && a[2*i+1]>a[max]){
          max=2*i+1;
     }

     if(max!=i){
          swap(a[i], a[max]);
          heapify(a, max, n);
     }
}    


void heapsort(vector<int> &a){

     int n=a.size()-1;
     for(int i=n; i>=1; --i){
          swap(a[1], a[i]);
          heapify(a, 1, i-1);
     }
}


int main(){
     int n;
     cin>>n;

     vector<int> a(n+1);

     for(int i=1; i<=n; ++i){
          cin>>a[i];
     }

     for(int i=n/2; i>=1; --i){
          heapify(a, i, n);
     }
     heapsort(a);

     for(int i=1; i<=n; ++i){
          cout<<a[i]<<" ";
     }
     
}