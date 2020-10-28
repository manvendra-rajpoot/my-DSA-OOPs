#include <iostream>
using namespace std;

void inPlaceHeapSort(int* pq, int n){
    //Build the heap within array

    for(int i=1;i<n;++i){
    //Up-Heapify
    int childIndex = i;
        while (childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else{
                 break;
            }
            childIndex = parentIndex;
        }
    }
    //Removing element one-by-one
    //Down-Heapify
    int tempArrSize = n;
    while(tempArrSize > 1){
        int temp = pq[0];
        pq[0] = pq[tempArrSize - 1];
        pq[tempArrSize - 1] = temp;
        tempArrSize--;

        int pIndex = 0;
        int lcIndex = 2 * pIndex + 1;
        int rcIndex = 2 * pIndex + 2;
        while (lcIndex < tempArrSize){
            int minIndex = pIndex;
            if (pq[minIndex] > pq[lcIndex]){
                minIndex = lcIndex;
            }
            if (rcIndex < tempArrSize && pq[minIndex] > pq[rcIndex]){
                minIndex = rcIndex;
            }
            if (minIndex == pIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[pIndex];
            pq[pIndex] = temp;

            pIndex = minIndex;
            lcIndex = 2 * pIndex + 1;
            rcIndex = 2 * pIndex + 2;
        }
    }  
}
int main(){
    int arr[] = {2,3};
    inPlaceHeapSort(arr,sizeof(arr)/sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
    return 0;
}