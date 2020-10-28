#include<iostream>
using namespace std;
#define  rep(i,a,n) for(int i=a;i<n;++i)

int firstInd(int* a, int n,int const x,const int size) {
    if(n==0)return -1;
    if(a[0]==x)return size-n;
    int smallOutput=firstInd(a+1,n-1,x,size);
    return smallOutput;

}
int main(){
    int n;cin>>n;
    int* a = new int[n];
    rep(i,0,n)cin>>a[i];
    int x;cin>>x;//find first index of x if not possible return -1
    cout<<firstInd(a,n,x,n)<<'\n';

    delete [] a;
    return 0;
}