#include<bits/stdc++.h>
using namespace std;

struct node{
     char chr;
     int freq;
     struct node* left, *right;
     node(char c, int f){
          chr=c;
          freq=f;
          left=right=nullptr;
     }
     node(char c, int f, node* l, node* r){
          chr=c;
          freq=f;
          left=l;
          right=r;
     }
};

struct cmp{
     bool operator()(node* n1, node* n2){
          return n1->freq>n2->freq;
     }
};


void getcode(string code, vector<string> &ans, node* root){
     if(!root)return;
     if(!root->left && !root->right){
          ans.push_back(code+root->chr);
     }
     getcode(code+'0', ans, root->left);
     getcode(code+'1', ans, root->right);
}

int main(){
     int n;
     cout<<"Enter the number of char: ";
     cin>>n;
     char crr[n];
     int fq[n];

     priority_queue<node*, vector<node*>, cmp> pq;
     for(int i=0;i<n; ++i){
          cin>>crr[i];
          cin>>fq[i];
          node* k=new node(crr[i], fq[i], NULL, NULL);
          pq.push(k);
     }

     while(pq.size()>1){
          node* n1=pq.top();
          pq.pop();
          node* n2=pq.top();
          pq.pop();

          node* k=new node('0', n1->freq+n2->freq, n1, n2);
          pq.push(k);
     }

     node* root=pq.top();
     vector<string> ans;
     string code="";
     getcode(code, ans, root);

     for(auto str:ans){
          cout<<str<<" ";
     }
}