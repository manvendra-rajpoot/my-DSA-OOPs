#include<iostream>
using namespace std;
void merge(int* a,int si,int ei){
    int sz=ei-si+1, mid=si+(ei-si)/2;
    int* b = new int[sz];
    int i=si,j=mid+1,k=0;
    while(i<=mid && j<=ei){
        if(a[i]<a[j])b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=ei){
        b[k++]=a[j++];
    }
    for(int i=si,j=0;j<sz;){
        a[i++]=b[j++];
    }
    delete [] b;
}
void mergeSort(int* a, int si, int ei){
    if(si>=ei)return;//arr size becomes 0 or 1
    
    int mid = si + (ei-si)/2;
    mergeSort(a,si,mid);
    mergeSort(a,mid+1,ei);
    merge(a,si,ei);
}
int main(){
    int n;cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++)cin>>a[i];
    mergeSort(a,0,n-1);
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
    cout<<'\n';
    delete [] a;
    return 0;
}