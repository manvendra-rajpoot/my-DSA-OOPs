#include<iostream>
using namespace std;
#include<vector>
#define  rep(i,a,n) for(int i=a;i<n;++i)

void allInd(int* a, int n,int const x,vector<int>& output) {
    if(n==0)return;
    if(a[n-1]==x)output.insert(output.begin(),n-1);
    allInd(a,n-1,x,output);
}

int main(){
    int n;cin>>n;
    int* a = new int[n];
    vector<int> output;
    rep(i,0,n)cin>>a[i];
    int x;cin>>x;//find first index of x if not possible return -1
    allInd(a,n,x,output);
    if(output.size()==0)cout<<-1;
    else{
        rep(i, 0, output.size()) cout << output[i] << " ";
    }
    cout<<'\n';
    delete [] a;
    return 0;
}