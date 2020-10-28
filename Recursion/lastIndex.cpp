#include<iostream>
using namespace std;
#define  rep(i,a,n) for(int i=a;i<n;++i)

int lastInd(int* a, int n,int const x) {
    if(n==0)return -1;
    if(a[n-1]==x)return n-1;
    int smallOutput=lastInd(a,n-1,x);
    return smallOutput;

}
int main(){
    int n;cin>>n;
    int* a = new int[n];
    rep(i,0,n)cin>>a[i];
    int x;cin>>x;//find first index of x if not possible return -1
    cout<<lastInd(a,n,x)<<'\n';

    delete [] a;
    return 0;
}