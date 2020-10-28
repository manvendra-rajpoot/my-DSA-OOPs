#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T elem) : data(elem), next(NULL) {}
};

template <typename T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size; //no. of elem in stack

public:
    Queue(){
        head = tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head == NULL;
    }
    void enqueue(T elem){
        Node<T> *t = new Node<T>(elem);
        if (!head){
            head = tail = t;
        }
        else{
            tail->next = t;
            tail = t;
        }
        size++;
    }
    T dequeue(){
        if (isEmpty()){
            cout << "Empty Queue!\n";
            return 0;
        }
        Node<T> *t = head;
        T value = t->data;
        head = head->next;
        size--;
        if(size==0){
            tail = head;
        }
        delete t;
        return value;
    }
    T front(){
        if (isEmpty()){
            cout << "Empty Queue!\n";
            return 0;
        }
        return head->data;
    }
};