#include <iostream>
using namespace std;
#include "pair.h"

int main(){
    Pair< Pair<int,int>, double> p1;
    p1.setY(11.11);

    Pair<int,int> p;
    p.setX(1);
    p.setY(2);
    // cout<<p.getX()<<" "<<p.getY()<<"\n";
    p1.setX(p);
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<'\n';
}
