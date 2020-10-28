#include <iostream>
#include <queue>
#include "treeNode.h"
using namespace std;
#define pb push_back
#define sz(v) v.size()
#define rep(i,a,n) for(int i=a;i<n;i++) 

treeNode<int> *takeInput(){
    cout<<"Enter data: ";
    int rootdata;
    cin>>rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);
    cout<<"Enter no. of children: ";
    int n;
    cin>>n;
    rep(i,0,n){
        treeNode<int> *child = takeInput();
        root->children.pb(child);
    }
    return root;
}
void printTree(treeNode<int>* root){
    if(!root){ //edge case not base
        return;
    }
    //base case is implicitily handled
    cout<<root->data<<':';
    rep(i,0,sz(root->children)){
        cout<<root->children[i]->data<<",";
    }
    cout<<'\n';
    rep(i,0,sz(root->children)){
        printTree(root->children[i]);
    }
}

treeNode<int>* takeInputLevelWise(){
    cout << "Enter root data: ";
    int rootdata;
    cin >> rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);
    queue<treeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        treeNode<int>* front = q.front();
        q.pop();
        cout<<"Enter the no. of children of "<<front->data<<": ";
        int n;
        cin>>n;
        rep(i,0,n){
            cout<<"Enter the "<<i<<"th child of "<<front->data<<": ";
            int childdata;
            cin>>childdata;
            treeNode<int>* child = new treeNode<int>(childdata);
            q.push(child);
            front->children.pb(child);
        }
    }
    return root;
}
void printTreeLevelWise(treeNode<int>* root){
    if(!root){ //edge case
        return;
    }
    queue<treeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        treeNode<int> *front = q.front();
        q.pop();
        cout<<front->data<<":";
        rep(i,0,sz(front->children)){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<'\n';
    }
}

int countNodes(treeNode<int>* root){
    if(!root)return 0;
    int cnt=0;
    rep(i,0,sz(root->children)){
        cnt += countNodes(root->children[i]);
    }
    return 1 + cnt;
}

int heightOfTree(treeNode<int>* root){
    if(!root)return 0;
    int ht = 0;
    rep(i, 0, sz(root->children)){
        ht = max(ht, heightOfTree(root->children[i]));
    }
    return 1 + ht; 
}

void printAtLevelK(treeNode<int>* root,int k){
    if (!root) return;
    if(k==0){
        cout<<root->data<<' ';
        return;
    }
    rep(i, 0, sz(root->children)){
        printAtLevelK(root->children[i],k-1);
    }
}

int noOfleafNodes(treeNode<int>* root){
    if(!root) return 0;
    if(sz(root->children)==0)return 1;
    int leafcnt = 0;
    rep(i,0,sz(root->children)){
        leafcnt += noOfleafNodes(root->children[i]);
    }
    return leafcnt;
}

void preOrder(treeNode<int>* root){
    if(!root) return;
    cout<<root->data<<'\n';
    rep(i,0,sz(root->children)){
        preOrder(root->children[i]);
    }
}
void postOrder(treeNode<int> *root){
    if (!root) return;
    rep(i, 0, sz(root->children)){
        postOrder(root->children[i]);
    }
    cout << root->data << '\n';
}
/* InOrder is not defined for "Generic Trees"! */

void deleteTree(treeNode<int> *root){
    if (!root) return;
    rep(i, 0, sz(root->children)){
        deleteTree(root->children[i]);
    }
    delete root; 
}

int main(){
    //treeNode<int> *root1 = takeInput(); 
    //printTree(root1);
    treeNode<int> *root1 = takeInputLevelWise();
    printTreeLevelWise(root1);
    cout << "cnt: " << countNodes(root1) << '\n';
    cout << "ht: " << heightOfTree(root1) << '\n';
    cout << "At level k: ";
    printAtLevelK(root1,2);
    cout<<"\nnoOfLeaves: "<<noOfleafNodes(root1)<<'\n';

    deleteTree(root1); //good use of postOrder
    
    /*  One another way to delete 'TREE' is defining Destructor 
        and after that we can directly use 

        delete(root1);
    */

    return 0;
}
