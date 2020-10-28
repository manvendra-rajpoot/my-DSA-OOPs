#include <iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T elem): data(elem), next(NULL){ }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size; //no. of elem in stack

    public:
    Stack(){
        head = NULL;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head == NULL;

    }
    void push(T elem){
        Node<T> *t = new Node<T>(elem); 
        if(!head){
            head = t;
        }
        else{
            t->next = head;
            head = t;
        }
        size++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Empty Stack!\n";
            return 0;
        }
        Node<T> *t = head;
        T value = t->data;
        head = head->next;
        delete t;
        size--;
        return value;
    }
    T top(){
        if (isEmpty()){
            cout << "Empty Stack!\n";
            return 0;
        }
        return head->data;
    }
};