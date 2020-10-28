#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDupli(int* a,int n){
    vector<int> v;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++){
        if(seen.count(a[i])>0)continue;
        seen[a[i]] = true;
        v.push_back(a[i]);
    }
    return v;
}
int main(){
    int a[] = {100001,100001,1999999,1999999,234,3456787};
    vector<int> v = removeDupli(a,sizeof(a)/sizeof(int));
    for(int i=0;i<v.size();++i){
        cout<<v.at(i)<<' ';
    }
    cout<<'\n';
    return 0;
} 
