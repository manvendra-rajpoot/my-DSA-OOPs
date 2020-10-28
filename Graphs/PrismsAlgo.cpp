#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int* weight,bool* visited,int v){
    int minWeightedVertex=-1;
    for(int i=0;i<v;++i){
        if(!visited[i]){
            if(minWeightedVertex==-1 || (weight[minWeightedVertex]>weight[i])){
                minWeightedVertex=i;
            }
        }
    }
    return minWeightedVertex;
}

void Prisms(int** edges, int v){
    int* parent = new int[v];
    int* weight = new int[v];
    bool* visited = new bool[v];
    for(int i=0;i<v;++i){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    //Let source(head) vertex be "0"
    parent[0]=-1;
    weight[0]=0;

    for(int i=0;i<v;++i){
        //find min. weighted vertex that is unvisited
        int minWt_V=findMinVertex(weight,visited,v);
        visited[minWt_V]=true;
        
        //exploring un-visited neigbhour & finding min.Weighted Vertex
        for(int j=0;j<v;j++){
            if(edges[minWt_V][j]!=0 && !visited[j]){
                if(edges[minWt_V][j]<weight[j]){
                    weight[j]=edges[minWt_V][j];
                    parent[j]=minWt_V;
                }
            }
        }
    }
    for(int i=1;i<v;++i){
        if(i>parent[i]){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<'\n';
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<'\n';
        }
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;
}

int main(){
    int v, e;cin>>v>>e;
    int** edges = new int*[v];
    for (int i=0;i<v;++i) {
        edges[i]=new int[v];
        for (int j=0;j<v;++j)edges[i][j]=0;
    }

    for (int i=0;i<e;++i) {
        int src, dist,wt;
        cin>>src>>dist>>wt;
        edges[src][dist]=wt;
        edges[dist][src]=wt;
    }
    cout<<"\nMST by Prism's Algo => \n";
    Prisms(edges,v);

    for (int i=0;i<v;++i)delete[] edges[i];
    delete[] edges;
    return 0;
}