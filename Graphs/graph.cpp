#include <iostream>
#include <queue>//for bfs
#include <vector>
#include <unordered_map>
using namespace std;
#define pb push_back

//dfs - Adj. Matrix
void printDFS(int** edges, int v, bool* visited, int sv){
    visited[sv]=true;
    cout<<sv<<"\n";
    for(int i=0;i<v;++i){
        if(i==sv)continue;
        if(edges[sv][i]==1){
            if(!visited[i]){
                printDFS(edges,v,visited,i);
            }
        }
    }
}
void DFS(int** edges, int v) {
    bool* visited = new bool[v];
    for (int i=0;i<v;++i)visited[i]=false;

    for (int i=0;i<v;++i) {
        if (!visited[i])printDFS(edges, v, visited, i);
    }
    delete[] visited;
}
//bfs- Adj. Matrix
void printBFS(int** edges,int v,bool* visited, int sv){
    queue<int> Q;
    Q.push(sv);
    visited[sv]=true;
    while(!Q.empty()){
        int currV= Q.front();
        Q.pop();
        cout<<currV<<"\n";
        for(int i=0;i<v;++i){
            if(i==currV)continue;
            if(edges[currV][i]==1 && !visited[i]){
                Q.push(i);
                visited[i]=true;
            }
        }
    }
}
void BFS(int** edges, int v){
    bool* visited = new bool[v];
    for (int i=0;i<v;++i)visited[i]=false;

    for (int i=0;i<v;++i) {
        if (!visited[i])printBFS(edges, v, visited, i);
    }
    delete[] visited;

}

bool hasPath(int** edges,int v,int src,int dest){
    //by bfs
    bool flag=false;
    queue<int> Q;
    bool* visited = new bool[v];
    for(int i=0;i<v;++i)visited[i]=false;
    Q.push(src);
    visited[src]=true;
    while (!Q.empty()) {
        int currV= Q.front();
        Q.pop();
        for (int i=0;i<v;++i) {
            if (i==currV)continue;
            if (edges[currV][i]==1 && !visited[i]) {
                if(i==dest){
                    flag=true;
                    break;
                }
                Q.push(i);
                visited[i]=true;
            }
        }
        if(flag)break;
    }
    delete[] visited;
    return flag;
}

vector<int> getPathBFS(int** edges,int v,int src,int dest){
    if(src==dest){
        vector<int> res(1,dest);
        return res;
    }
    bool flag=false;
    queue<int> Q;
    bool* visited = new bool[v];
    for (int i=0;i<v;++i)visited[i]=false;

    unordered_map<int, int> parentV;
    Q.push(src);
    visited[src]=true;
    while (!Q.empty()) {
        int currV= Q.front();
        Q.pop();
        for (int i=0;i<v;++i) {
            if (i==currV)continue;
            if (edges[currV][i]==1 && !visited[i]) {
                if (i==dest) {
                    flag=true;
                    parentV[i]=currV;
                    break;
                }
                Q.push(i);
                parentV[i]=currV;
                visited[i]=true;
            }
        }
        if (flag)break;
    }
    
    vector<int> path(1,dest);
    int curr=dest;
    do{
        int x=parentV[curr];
        path.insert(path.begin(),x);
        curr=x;
    }while(curr!=src);

    delete[] visited;
    return path;
}

vector<int> getPathDFSHelper(int** edges,int v,int sv,int ev,bool* visited){
    visited[sv]=true;
    if (sv==ev) {
        vector<int> res;
        res.pb(ev);
        return res;
    }
    for(int i=0;i<v;i++){
        if(i==sv)continue;
        if (edges[sv][i]==1 && !visited[i]) {
            vector<int> res=getPathDFSHelper(edges, v, i, ev, visited);
            
            if(res.size()==0)continue;
            if(res[0]!=i){ //for size==1
                res.insert(res.begin(),i);
            }
            if(res.size()>0) {
                return res;
            }
        }
    }
    vector<int> vacant;
    return vacant;
}
vector<int> getPathDFS(int** edges,int v,int src,int dest){
    bool* visited = new bool[v];
    for (int i=0;i<v;++i)visited[i]=false;
    vector<int> path;
    path = getPathDFSHelper(edges,v,src,dest,visited);
    if(path.size()>1)path.insert(path.begin(),src);
    delete [] visited;
    return path;
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
    int src,dest;
    cin>>src>>dest;

    cout<<"dfs\n";
    DFS(edges,v);
    cout<<"bfs\n";
    BFS(edges,v);
    
    cout<<"Has Path b/w "<<src<<" & "<< dest <<"=> "<<hasPath(edges,v,src,dest)<<'\n';
    
    cout<<"Get Path by DFS b/w "<<src<<" & "<< dest <<"=> ";
    vector<int> path1= getPathBFS(edges, v, src, dest);
    for (int i=0;i<path1.size();++i) {
        cout<<path1[i]<<",";
    }
    cout<<'\n';

    cout<<"Get Path by DFS b/w "<<src<<" & "<< dest <<"=> ";
    vector<int> path2= getPathDFS(edges,v,src,dest);
    for (int i=0;i<path2.size();++i) {
        cout<<path2[i]<<",";
    }
    cout<<'\n';

    for(int i=0;i<v;++i)delete [] edges[i];
    delete [] edges;

    return 0;
}