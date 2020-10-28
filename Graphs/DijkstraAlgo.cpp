#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int* distance,bool* visited,int v){
    int minDistanceVertex=-1;
    for(int i=0;i<v;++i){
        if(!visited[i]){
            if(minDistanceVertex==-1 || (distance[minDistanceVertex]>distance[i])){
                minDistanceVertex=i;
            }
        }
    }
    return minDistanceVertex;
}

void Dijkstra(int** edges, int v){
    int* distance = new int[v];//distance from assumed source
    bool* visited = new bool[v];
    for(int i=0;i<v;++i){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    //Let source(head) vertex be "0"
    distance[0]=0;

    for(int i=0;i<v;++i){
        //find min. distance vertex that is unvisited
        int minDistance_V=findMinVertex(distance,visited,v);
        visited[minDistance_V]=true;
        
        //exploring un-visited neigbhour & finding min.Weighted Vertex
        for(int j=0;j<v;++j){
            if(edges[minDistance_V][j]!=0 && !visited[j]){
                int dist=distance[minDistance_V]+edges[minDistance_V][j];
                if(dist<distance[j])distance[j]=dist; 
            }
        }
    }
    for(int i=0;i<v;++i){
        cout<<i<<" "<<distance[i]<<'\n';
    }
    
    delete [] distance;
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
    cout<<"\nDistance from src => \n";
    Dijkstra(edges,v);

    for (int i=0;i<v;++i)delete[] edges[i];
    delete[] edges;
    return 0;
}