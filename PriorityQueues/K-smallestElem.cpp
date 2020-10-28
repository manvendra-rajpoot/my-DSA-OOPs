/*  Ques.=> Given a k-sorted array. 
    Get the array sorted in descending order
*/
#include <iostream>
#include <queue>
using namespace std;

void kSmallestElem(int* a,int n,int k,int* ans){
    priority_queue<int> p;
    for(int i = 0;i<k;++i){ //O(k*(logk))
        p.push(a[i]);
    }
    for(int i = k; i<n;++i){ //O((n-k)*(2*logk))
        if(p.top()>a[i]){
            p.pop();
            p.push(a[i]);
        }
    }
    int j = 0;
    while(!p.empty()){ // O(k*(logk))
        ans[j++] = p.top();
        p.pop();
    }
}

int main(){
    int k = 3;
    int arr[] = {10, 12, 6, 7, 9};
    int* output = new int[k];
    for(int i=0;i<k;++i)output[i]=-1;
    
    kSmallestElem(arr, sizeof(arr) / sizeof(int), k, output);
    for (int i = 0; i < k; i++){
        cout << output[i] << " ";
    }
    cout << '\n';
    delete [] output;
    return 0;
}