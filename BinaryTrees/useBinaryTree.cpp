#include <iostream> 
#include <queue>
#include "btNode.h"
using namespace std;

btNode<int>* takeInput(){
    cout<<"Enter data: ";
    int data;
    cin>>data; 
    if(data == -1){
        return NULL;
    }
    btNode<int>* root = new btNode<int>(data);
    btNode<int> *lchild = takeInput();
    btNode<int> *rchild = takeInput();
    root->left = lchild;
    root->right = rchild;
    return root;
}
void printBT(btNode<int>* root){
    if(!root){
        return;
    }
    cout<<root->data<<": ";
    if(root->left){
        cout<<"L="<<root->left->data<<" ";
    }
    if (root->right){
        cout << "R=" << root->right->data << " ";
    }
    cout<<'\n';
    printBT(root->left);
    printBT(root->right);
}

btNode<int>* takeInputLevelWise(){
    cout << "Enter root data: ";
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1){
        return NULL;
    }
    btNode<int> *root = new btNode<int>(rootdata);
    queue<btNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        btNode<int> *front = q.front();
        q.pop();
        int lchilddata,rchilddata;
        cout<<"Enter lchild of "<<front->data<<": ";
        cin>>lchilddata;
        if(lchilddata != -1){
            btNode<int> *lchild = new btNode<int>(lchilddata);
            front->left = lchild;
            q.push(lchild);
        }
        cout << "Enter rchild of " << front->data << ": ";
        cin >> rchilddata;
        if (rchilddata != -1){
            btNode<int> *rchild = new btNode<int>(rchilddata);
            front->right = rchild;
            q.push(rchild);
        }
    }
    return root;
}
void printBTLevelWise(btNode<int>* root){
    if(!root) return;
    queue<btNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        btNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<": ";
        if(front->left){
            cout<<"L="<<front->left->data<<" "; 
            q.push(front->left);
        }
        if(front->right){
            cout << "R=" << front->right->data << " ";
            q.push(front->right);
        }
        cout<<'\n';
    }
}
int countNodes(btNode<int>* root){
    if(!root) return 0;

    int lsideNodes = countNodes(root->left);
    int rsideNodes = countNodes(root->right);
    return 1 + lsideNodes + rsideNodes; 
}
int heightofBT(btNode<int>* root){ //O(n)
    if(!root) return 0;
    int ht = max(heightofBT(root->left),heightofBT(root->right));
    return 1 + ht;
}

void preOrder(btNode<int>* root){
    if(!root) return;
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(btNode<int> *root){
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}
void inOrder(btNode<int> *root){
    if (!root) return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

btNode<int>* bulidTreeUsingInAndPreHelper(int* in,int* pre,int inS,int inE,int preS,int preE){
    if((inS > inE) || (preS > preE)){
        return NULL;
    }
    int rootdata = pre[preS];
    btNode<int>* root = new btNode<int>(rootdata);
    int rootIndex = -1;
    for(int i= inS;i<=inE;++i){
        if(in[i]==rootdata){
            rootIndex = i;
            break; 
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = (lInE-lInS) + lPreS;
    int rPreS = lPreE +1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    root->left = bulidTreeUsingInAndPreHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->right = bulidTreeUsingInAndPreHelper(in,pre,rInS,rInE,rPreS,rPreE);
    return root;
}
btNode<int>* buildTreeUsingInAndPre(int* in,int* pre,int size){
    return bulidTreeUsingInAndPreHelper(in,pre,0,size-1,0,size-1);
}

btNode<int> *bulidTreeUsingInAndPostHelper(int *in,int *post,int inS,int inE,int postS,int postE){
    if ((inS > inE) || (postS > postE)){
        return NULL;
    }
    int rootdata = post[postE];
    btNode<int> *root = new btNode<int>(rootdata);
    int rootIndex = -1;
    for (int i = inS; i <= inE; ++i){
        if (in[i] == rootdata){
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex -1;
    int lPostS = postS;
    int lPostE = (lInE - lInS) + lPostS;
    int rPostS = lPostE + 1;
    int rPostE = postE-1;
    int rInS = rootIndex + 1;
    int rInE = inE;
    root->left = bulidTreeUsingInAndPostHelper(in, post, lInS, lInE, lPostS, lPostE);
    root->right = bulidTreeUsingInAndPostHelper(in, post, rInS, rInE, rPostS, rPostE);
    return root;
}
btNode<int> *buildTreeUsingInAndPost(int *in, int *post, int size){
    return bulidTreeUsingInAndPostHelper(in, post, 0, size - 1, 0, size - 1);
}

int diameter(btNode<int>* root){ //T(n) = O(n * heightofBT)
    if(!root) return 0;
    int option1 = heightofBT(root->left) + heightofBT(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}

//Better Approch for finding Diameter
pair<int,int> heightDiameter(btNode<int>* root){ //O(n)
    if(!root){
        pair<int,int> p;
        p.first = p.second = 0; //first = height, second  = diameter
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first, ld = leftAns.second;
    int rh = rightAns.first,rd = rightAns.second;

    int height = 1 + max(lh,rh); 
    int diameter = max((lh+rh),max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main(){
    /*  Sample Tree:
        1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    */

    /*int in[] = {4,2,5,1,8,6,9,3,7};
    int pre[] = {1,2,4,5,3,6,8,9,7};
    int post[] = {4,5,2,8,9,6,7,3,1};
    btNode<int>* root1 = buildTreeUsingInAndPre(in,pre,9);
    printBTLevelWise(root1);
    btNode<int> *root2 = buildTreeUsingInAndPost(in, post, 9);
    printBTLevelWise(root2);
    cout<<"\nPre: ";
    preOrder(root1);
    cout << "\nPre: ";
    preOrder(root2);
    */
    btNode<int> *root1 = takeInputLevelWise();
    printBTLevelWise(root1);
    pair<int,int> p = heightDiameter(root1);
    cout<<"ht: "<<p.first<<" dia: "<<p.second<<'\n';

    delete (root1);
    return 0;
}