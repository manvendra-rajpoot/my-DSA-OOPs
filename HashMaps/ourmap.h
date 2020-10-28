#include <string>
using namespace std;

template <typename V>
class mapNode{
    public:
    string key;
    V value;
    mapNode* next;

    mapNode(string str, V value){
        this->key = str;
        this->value = value;
        this->next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};
template <typename V>
class ourmap{
    mapNode<V>** bucket;
    int bucket_size;
    int count;//no. of elem in bucket array

    public:
    ourmap():bucket_size(5),count(0){
        this->bucket = new mapNode<V>*[bucket_size];
        for(int i=0;i<bucket_size;++i){
            bucket[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<bucket_size;++i){
            delete bucket[i];
        }
        delete [] bucket;
    }
    int size(){
        return count;
    }

    private:
    int getBucketIndex(string key){
        int hashCode = 0;
        int multiplyingCoeff = 1;
        for(int i=key.size()-1;i>-1;--i){
            hashCode += key[i] * multiplyingCoeff;
            hashCode = hashCode % bucket_size;
            multiplyingCoeff *= 31; //any prime number
            multiplyingCoeff = multiplyingCoeff%bucket_size;
        }
        return hashCode%bucket_size;
    }
    void reHash(){
        mapNode<V> **old_bucket = bucket;
        int old_bucket_size = bucket_size;
        bucket_size = 2*old_bucket_size;
        count = 0;
        bucket = new mapNode<V>* [bucket_size];
        for(int i=0;i<bucket_size;++i){
            bucket[i] = NULL;
        }
        for(int i=0;i< old_bucket_size;++i){
            mapNode<V> *head = old_bucket[i];
            while(head){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head = head->next;
            }
        }
        for (int i = 0; i < old_bucket_size; ++i){
            mapNode<V> *head = old_bucket[i];
            delete head;
        }
        delete old_bucket;
    }

    public:
    void insert(string key,V value){
        int index = getBucketIndex(key);
        mapNode<V>* head = bucket[index];
        while(head){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = bucket[index];
        mapNode<V> *temp = new mapNode<V>(key,value);
        temp->next = head;
        bucket[index] = temp;
        count++;
        double loadFactor = (1.0*count)/bucket_size;
        if(loadFactor>0.7){
            reHash();
        }
    }
     
    V remove(string key){
        int index = getBucketIndex(key);
        mapNode<V> *head = bucket[index];
        mapNode<V> *prev = NULL;
        while(head){
            if(head->key == key){
                if(!prev){
                    bucket[index] = head->next;
                }else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    V getValue(string key){
        int index = getBucketIndex(key);
        mapNode<V> *head = bucket[index];
        while(head){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    double getLoadFactor(){
        return (1.0*count)/bucket_size;
    }
};
