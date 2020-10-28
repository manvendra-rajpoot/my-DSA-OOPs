#include <vector>
// #include <climits>
using namespace std;

class PriorityQueue{
    private:
    vector<int> pq;
    public:
    PriorityQueue(){ }
    ~PriorityQueue(){ }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty())return 0;
        return pq.at(0);
    }
    void insertData(int elem){
        pq.push_back(elem);

        //Up-Heapify
        int childIndex = pq.size()-1;
        while(childIndex>0){
            int parentIndex = (childIndex - 1) / 2;
            if (pq.at(parentIndex) > pq.at(childIndex)){
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
    int removeMin(){
        if (isEmpty()){
            return 0;
        }
        /*We are consdering Min_Heap so deletion will be done at root */
        int ans = pq.at(0);
        pq.at(0) = pq.at(pq.size()-1);
        pq.pop_back();

        //Down-Heapify
        int pIndex = 0;
        int lcIndex = 2 * pIndex + 1;
        int rcIndex = 2 * pIndex + 2;
        while (lcIndex < pq.size()){
            int minIndex  = pIndex;
            if (pq[minIndex] > pq[lcIndex]){
                minIndex = lcIndex;
            }
            if (rcIndex < pq.size() && pq[minIndex] > pq[rcIndex]){
                minIndex = rcIndex;
            }
            if(minIndex == pIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[pIndex];
            pq[pIndex] = temp;

            pIndex = minIndex;
            lcIndex = 2 * pIndex + 1;
            rcIndex = 2 * pIndex + 2;
        }
        return ans;
    }

};