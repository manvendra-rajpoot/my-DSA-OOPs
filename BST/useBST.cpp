#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include "bstNode.h"
#include "../LinkedList/Node.h"
 
using namespace std;

bstNode<int> *takeInputLevelWise(){
    cout << "Enter root data: ";
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1){
        return NULL;
    }
    bstNode<int> *root = new bstNode<int>(rootdata);
    queue<bstNode<int> *> q;
    q.push(root);
    while (!q.empty()){
        bstNode<int> *front = q.front();
        q.pop();
        int lchilddata, rchilddata;
        cout << "Enter lchild of " << front->data << ": ";
        cin >> lchilddata;
        if (lchilddata != -1){
            bstNode<int> *lchild = new bstNode<int>(lchilddata);
            front->left = lchild;
            q.push(lchild);
        }
        cout << "Enter rchild of " << front->data << ": ";
        cin >> rchilddata;
        if (rchilddata != -1){
            bstNode<int> *rchild = new bstNode<int>(rchilddata);
            front->right = rchild;
            q.push(rchild);
        }
    }
    return root;
}
void printBTLevelWise(bstNode<int> *root){
    if (!root)
        return;
    queue<bstNode<int> *> q;
    q.push(root);
    while (!q.empty()){
        bstNode<int> *front = q.front();
        q.pop();
        cout << front->data << ": ";
        if (front->left)
        {
            cout << "L=" << front->left->data << " ";
            q.push(front->left);
        }
        if (front->right)
        {
            cout << "R=" << front->right->data << " ";
            q.push(front->right);
        }
        cout << '\n';
    }
}
bool search(bstNode<int>* root,int key){
    if(!root){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data<key){
        return search(root->right,key);
    }
    else{
        return search(root->left, key);
    }
}
/*Print Nodes between the Range*/
void printBtwRangeK1K2(bstNode<int>* root,int k1 ,int k2){
    if(!root){
        return;
    }
    if(root->data >= k1 && root->data <=k2){
        cout<< root->data <<" ";
    }
    if (root->data > k1){
        printBtwRangeK1K2(root->left, k1, k2);
    }
    if(root->data <= k2){
        printBtwRangeK1K2(root->right,k1,k2);
    }
}

int findMin(bstNode<int>* root){
    if(!root){
        return INT_MAX;
    }
    return min(root->data, min(findMin(root->left),findMin(root->right)));
}
int findMax(bstNode<int>* root){
    if(!root){
        return INT_MIN;
    }
    return max(root->data, max(findMax(root->left),findMax(root->right)));
}
/*Check if given BT is BST */
bool isBST(bstNode<int>* root){ //O(n * height)
    if(!root){
        return true;
    }
    int leftMax = findMax(root->left);
    int rightMin = findMin(root->right);
    bool ans = (leftMax<root->data)&&(rightMin>=root->data)&&isBST(root->left)&&isBST(root->right);
    return ans;
}

class triplet{
    public:
        bool isBst;
        int minimum, maximum;
};
triplet isBST2(bstNode<int>* root){ /*Bottom to Top Approach - O(n)*/
    if(!root){
        triplet res;
        res.isBst = true;
        res.minimum = INT_MAX;
        res.maximum = INT_MIN;
        return res;
    }
    triplet leftAns = isBST2(root->left);
    triplet rightAns = isBST2(root->right);
    int minimum = min(root->data,min(leftAns.minimum,rightAns.minimum));
    int maximum = max(root->data,max(leftAns.maximum,rightAns.maximum));
    bool isBst = (leftAns.maximum<root->data)&&(rightAns.minimum>=root->data)&&leftAns.isBst&&rightAns.isBst; 
    triplet res;
    res.isBst = isBst;
    res.minimum = minimum;
    res.maximum = maximum;
    return res;
}

bool isBST3(bstNode<int>* root,int minimum = INT_MIN,int maximum = INT_MAX){/*Top to Bottom - O(n)*/
    if(!root){
        return true;
    }
    if(root->data>maximum || root->data<minimum){ //out of range;
        return false;
    }
    bool isleftBst = isBST3(root->left, minimum, root->data - 1);
    bool isrightBst = isBST3(root->right, root->data, maximum);
    return isleftBst&&isrightBst;
}
/*Construct BST from sorted array*/
bstNode<int>* bstFromSortedArrHelper(int* a,int si,int ei){
    if(si>ei){
        return NULL;
    }
    int rootIndex = si+(ei-si)/2;
    int rootdata = a[rootIndex];
    bstNode<int>* root = new bstNode<int>(rootdata);
    root->left = bstFromSortedArrHelper(a, si, rootIndex - 1);
    root->right = bstFromSortedArrHelper(a, rootIndex + 1, ei);
    return root;
}
bstNode<int> *bstFromSortedArr(int *a,int size){
    return bstFromSortedArrHelper(a,0,size-1);
}
/*Construct sorted LL from BST*/
Pair bstToLL(bstNode<int>* root){
    if(!root){
        Pair p;
        p.head = p.tail = NULL;
        return p;
    }
    Node* mid = new Node(root->data);
    Pair leftAns = bstToLL(root->left);
    Pair rightAns = bstToLL(root->right);
    
    mid->next = rightAns.head;
    if(leftAns.tail)leftAns.tail->next = mid;
    
    Pair finalAns;
    if(leftAns.head)finalAns.head = leftAns.head;
    else finalAns.head = mid;
    
    if(rightAns.tail)finalAns.tail = rightAns.tail;
    else finalAns.tail = mid;
    
    return finalAns;
}
void printLL(Node *head){
    while (head){
        cout << head->data << "->";
        head = head->next;
    }
    cout << '\n';
}

/*Get Path b/w root and given node*/
vector<int>* getRootToNodePath(bstNode<int>* root,int key){
    if(!root){
        return NULL;
    }
    if(root->data == key){
        vector<int>* path = new vector<int>();
        path->push_back(root->data);
        return path;
    }
    vector<int>* leftAns = getRootToNodePath(root->left,key);
    if(leftAns){
        leftAns->push_back(root->data);
        return leftAns;
    }
    vector<int> *rightAns = getRootToNodePath(root->right, key);
    if(rightAns){
        rightAns->push_back(root->data);
        return rightAns;
    }
    else{
        return NULL;
    }
}

int main(){
    /*
        Sample tree:
        5 3 10 2 4 8 12 -1 -1 -1 -1 -1 9 -1 -1 -1 -1  =>BST
        5 3 10 2 4 8 12 -1 -1 -1 -1 -1 10 -1 -1 -1 -1 =>not BST
    
    */
     bstNode<int>* root1 = takeInputLevelWise();
     printBTLevelWise(root1);
     /*cout << search(root1, 1) << '\n';
     cout << search(root1, 12) << '\n';
     cout << "B/w k1 & k2: ";khushbu rajpoot
     printBtwRangeK1K2(root1,4,8);
     cout<<'\n';
     cout<<"isBst1:"<<isBST(root1)<<'\n';
     triplet ans =  isBST2(root1);
     cout<<"isBst2:"<<ans.isBst<<" min:"<<ans.minimum<<" max:"<<ans.maximum<<'\n';
     cout << "isBst3:" << isBST3(root1) << '\n';

     int arr[] = {2,3,4,5,8,9,10,12};
     bstNode<int> *root2 = bstFromSortedArr(arr,sizeof(arr)/sizeof(int));
     printBTLevelWise(root2);
     delete (root1);
     delete (root2);*/
     Pair ll1 = bstToLL(root1);
     printLL(ll1.head);
     vector<int>* path = getRootToNodePath(root1,9);
     for(int i = 0;i < path->size();++i){
         cout<< path->at(i)<<" ";
     }
     cout<<'\n';
     delete(root1);
     delete(path);
     return 0;
}