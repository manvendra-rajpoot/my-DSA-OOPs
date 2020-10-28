#include<iostream>
using namespace std;
#define  rep(i,a,n) for(int i=a;i<n;++i)

bool is_sorted(int* a, int size) {
    if(size==0 || size==1)return true;
    if(a[0]>a[1])return false;
    
    bool smallOutput=is_sorted(a+1,size-1);
    return smallOutput;
}
int main(){
    int n;cin>>n;
    int* a = new int[n];
    rep(i,0,n)cin>>a[i];
    cout<<is_sorted(a,n)<<'\n';

    delete [] a;
    return 0;
}