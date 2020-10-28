#include <iostream>
#include "PriorotyQueue.h"
using namespace std;

int main(){
    PriorityQueue p;
    p.insertData(100);
    p.insertData(10);
    p.insertData(15);
    p.insertData(4);
    p.insertData(17);
    p.insertData(21);
    p.insertData(67);
    cout << p.getSize() << "\n";
    cout << p.getMin() << "\n";
    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<'\n';
}