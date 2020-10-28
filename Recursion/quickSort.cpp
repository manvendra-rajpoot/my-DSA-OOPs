#include<iostream>
using namespace std;
int partition(int* a,int si,int ei){
    int pivot=a[si], index=si ,cnt=0;//count of integer less than pivot;
    for(int i=si+1;i<=ei;++i){
        if(a[i]<pivot)cnt++;
    }
    index+=cnt;
    if(index==si)return index;
    
    swap(a[si],a[index]);
    int i=si,j=ei;
    while(i<index && j>index){
        if(a[i]<pivot)i++;
        if(a[j]>=pivot)j--;

        else if(a[i]>=pivot&&a[j]<pivot){
            swap(a[i++], a[j--]);
        }
    }
    return index;  
}
void quickSort(int* a, int si, int ei){
    if(si>=ei)return;//arr size becomes 0 or 1
    
    int partition_index = partition(a,si,ei);
    quickSort(a,si,partition_index-1);
    quickSort(a,partition_index+1,ei);
}
int main(){
    int n;cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
    cout<<'\n';
    delete [] a;
    return 0;
}