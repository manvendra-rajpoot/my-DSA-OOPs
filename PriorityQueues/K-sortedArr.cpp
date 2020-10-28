/*  Ques.=> Given a k-sorted array. 
    Get the array sorted in descending order
*/
#include <iostream>
#include <queue>
using namespace std;

void kSortedArr(int* a,int n,int k){
    priority_queue<int> p;
    for(int i=0;i<k;++i){ // O(k*(logk))
        p.push(a[i]);
    }
    int j = 0;
    for(int i=k;i<n;++i){ // O((n-k)*(logk))
        a[j++] = p.top();
        p.pop();
        p.push(a[i]);
    }
    while(!p.empty()){ // O(k*(logk))
        a[j++] = p.top();
        p.pop();
    }
}

int main(){
    int arr[] = {10,12,6,7,9};
    kSortedArr(arr, sizeof(arr) / sizeof(int),3);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
    return 0;
}