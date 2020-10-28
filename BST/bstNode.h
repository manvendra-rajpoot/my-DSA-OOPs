template <typename T>
class bstNode{
    public:
    T data;
    bstNode<T> *left, *right;
    bstNode(T elem){
        this->data = elem;
        left = right = NULL;
    }
    ~bstNode(){
        delete left;
        delete right;
    }
};

//for LL
/*class Node{
public:
    int data;
    Node *next;
    Node(int x) : data(x){
        next = NULL;
    }
};
class Pair{
    public:
    Node *head, *tail;
};
*/ 