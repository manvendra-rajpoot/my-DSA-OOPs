//Simple implementation can be improved by unionByRank and PathCompression
//kruskal is a Greedy algo
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int src,dest,weight;
};

bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;
}

int findParent(int v,int* parent){
    if(parent[v]==v)return v;
    return findParent(parent[v],parent);
}

void kruskals(int v,int e,edge* input){
    sort(input,input+e,compare);
    edge* output = new edge[v-1];
    int* parent=new int[v];
    for(int i=0;i<v;++i)parent[i]=i;

    int count=0,j=0;
    while (count<v-1) {
        edge currEdge=input[j++];
        int srcParent=findParent(currEdge.src,parent);
        int destParent=findParent(currEdge.dest, parent);

        if(srcParent!=destParent){
            output[count++]=currEdge;
            parent[destParent]=srcParent;
        }
    }
    for(int i=0;i<v-1;++i){
        if(output[i].src>output[i].dest){
            cout<<output[i].dest<<" "<<output[i].src<<" "
                <<output[i].weight<<'\n';
        }
        else{
            cout<<output[i].src<<" "<<output[i].dest<<" "
                <<output[i].weight<<'\n';
        }
    }
    
    delete [] parent;
    delete [] output;
}

int main(){
    int v,e;
    cin>>v>>e;
    edge* input = new edge[e];

    for(int i=0;i<e;++i){
        cin>>input[i].src>>input[i].dest>>input[i].weight;
    }
    cout<<"\nMST by kruskal's Algo => \n";
    kruskals(v,e,input);
    
    delete []  input;
    return 0;
}