//Ques. => Printing all connected Components.
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
void printDFS(int** edges, int v, bool* visited, int sv,vector<int> &cc) {
    visited[sv]=true;
    cc.pb(sv);
    for(int i=0;i<v;++i){
        if(i==sv)continue;
        if(edges[sv][i]==1){
            if(!visited[i]){
                printDFS(edges,v,visited,i,cc);
            }
        }
    }
}
vector<vector<int>> connectedComponents(int** edges, int v) {
    bool* visited = new bool[v];
    for (int i=0;i<v;++i)visited[i]=false;
    vector< vector<int> > output;
    for (int i=0;i<v;++i) {
        if (!visited[i]){
            vector<int> cc;
            printDFS(edges, v, visited, i,cc);
            output.pb(cc);
        }
    }
    delete[] visited;
    return output;
}

int main(){
    int v,e;cin>>v>>e;
    int** edges = new int*[v];
    for(int i=0;i<v;++i){ 
        edges[i]=new int[v];
        for(int j=0;j<v;++j)edges[i][j]=0;
    }

    for(int i=0;i<e;++i){
        int src, dist;
        cin>>src>>dist;
        edges[src][dist]=1;
        edges[dist][src]=1;
    }
    vector< vector<int> > cc=connectedComponents(edges,v);
    for(int i=0;i<cc.size();++i){
        for(int j=0;j<cc[i].size();++j){
            cout<<cc[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}