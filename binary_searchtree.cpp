#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int d){
        left=right=NULL;
        data=d;
    }
};

void insert(node* root, int key){
    node* temp=root;
    while(1){
        if(key<(temp->data)){
            if(temp->left==NULL){
                temp->left=new node(key);
                return;
            }else{
                temp=temp->left;
            }
            
        }else{
            if(temp->right==NULL){
                temp->right=new node(key);
                return;
            }else{
                temp=temp->right;
            }
            
        }
    }
}

void preorder(node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
        
        cout<<temp->data<<" ";
    }
} 



node* search(node* root, int key){
    node* temp=root;
    while(1){
        if(key==temp->left->data || key==temp->left->data){
            return temp;
        }else if(key<(temp->data)){
            temp=temp->left;
        }else if(key>(temp->data)){
            temp=temp->right;
        }
    }
}

node* deletenode(node* root, int key){
    if (root == NULL) return root;

  // Find the node to be deleted
    if (key < root->data)
        root->left = deletenode(root->left, key);
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    else {
        if (root->left == NULL) {
            node *temp = root->right;
            delete(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            delete(root);
            return temp;
        }
    node *temp;
    while (temp && temp->left != NULL)
        temp = temp->left;

    root->data = temp->data;

    root->right = deletenode(root->right, temp->data);
  }
  return root;
}

int ht(node* root){
    if(root==NULL)
        return 0;
    else{
        int hl=ht(root->left);
        int hr=ht(root->right);
        return (max(hl, hr)+1);
    }
}


void mirrorimg(node* root){
    if(root!=NULL){
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirrorimg(root->left);
        mirrorimg(root->right);
    }
    return;
}


node* clone(node* root){
     if (root == nullptr) {
        return nullptr;
    }

    node* temp = new node(root->data);

    temp->left = clone(root->left);
    temp->right = clone(root->right);

    return temp;
}


void iterative_inorder(node *root){
    stack<node*> st;
    st.push(root);
    node* temp=root;
    while(!st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }

        temp=st.top();
        st.pop();
        
        cout<<temp->data<<" ";
        
            temp=temp->right;
    }
}


void iterative_preorder(node *root){
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        cout<<root->data<<" ";
        st.pop();
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
}

void postorder_iterative(node* root) 
{ 
    if (root == NULL) 
        return; 
    stack<node*> s1, s2; 

    s1.push(root); 
    node* node; 
  
    while (!s1.empty()) { 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 

    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout<<node->data << " "; 
    } 
} 
  


int identicalTrees(node* a, node* b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a != NULL && b != NULL) {
        return (a->data == b->data
                && identicalTrees(a->left, b->left)
                && identicalTrees(a->right, b->right));
    }

    return 0;
}



int main(){
    node* root=new node(100);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int k;
        cin>>k;

        insert(root, k);
    }

    cout<<"The inorder traversal of tree is:";
    inorder(root);
    cout<<endl;
    cout<<"The preorder traversal of tree is:";
    preorder(root);
    cout<<endl;
    cout<<"The postorder traversal of tree is:";
    postorder(root);
    cout<<endl;

    cout<<"Level order traversal: ";
    levelorder(root);
    cout<<endl;

    cout<<"Height of the tree is: ";
    cout<<ht(root);
    cout<<endl;

    node* temp=clone(root);
    cout<<"Inorder traversal of clone";
    inorder(temp);
    cout<<endl;

    mirrorimg(temp);
    cout<<"Inorder traversal of mirror image";
    inorder(temp);
    cout<<endl;

    int g;
    cout<<"Enter the node that you want to delete: ";
    cin>>g;
    deletenode(root, g);
    inorder(root);
}