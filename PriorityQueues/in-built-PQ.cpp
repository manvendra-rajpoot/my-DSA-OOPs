#include <iostream>
#include <queue>
using namespace std;

int main(){
    //by default using MAX_HEAP
    priority_queue<int> pq1; //MAX_PriorityQueue

    priority_queue< int,vector<int>,greater<int> > pq; //MIN_PriorityQueue

    pq.push(5);
    pq.push(1);
    pq.push(15);
    pq.push(50);
    pq.push(33);
    pq.push(17);
    cout << pq.size() << '\n';
    cout<<pq.top()<<'\n';
    cout<<pq.empty()<<'\n';
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }cout<<'\n';
    return 0;
}