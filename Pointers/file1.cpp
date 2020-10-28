#include<iostream>
using namespace std;

int main(){
    int* p1;
    char* p2;
    double* p3;
    cout<<sizeof(p1)<<", "<<sizeof(p2)<<", "<<sizeof(p3)<<'\n';
    int a[10];
    a[2]=2;
    cout<<a[2]<<", "<<*(a+2)<<", "<<2[a]<<endl;
    return 0;
}
